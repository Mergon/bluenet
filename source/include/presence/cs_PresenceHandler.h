/*
 * Author: Crownstone Team
 * Copyright: Crownstone (https://crownstone.rocks)
 * Date: Nov 13, 2019
 * License: LGPLv3+, Apache License 2.0, and/or MIT (triple-licensed)
 */
#pragma once

#include <events/cs_EventListener.h>
#include <presence/cs_PresenceDescription.h>
#include <time/cs_SystemTime.h>

#include <list>
#include <optional>

/**
 * This handler listens for background advertisements to 
 * find out which users are in which room. It can be queried
 * by other 
 */
class PresenceHandler: public EventListener {
public: 
    enum class MutationType : uint8_t {
        NothingChanged              ,
        Online                      , // when no previous PresenceStateDescription was available but now it is
        Offline                     , // when a previous PresenceStateDescription was available but now it isn't
        LastUserExitSphere          , 
        FirstUserEnterSphere        , 
        OccupiedRoomsMaskChanged    ,
    };

private:
    // after this amount of seconds a presence_record becomes invalid.
    static const constexpr uint32_t presence_time_out_s = 10;

    /**
     * after this amount of seconds it is assumed that presencehandler would have received 
     * message from all devices in vicinity of this device.
     */
    static const constexpr uint32_t presence_uncertain_due_reboot_time_out_s = 30;

    // using a list because of constant time insertion/deletion of
    // any item in the container
    static const constexpr uint8_t max_records = 20;
    struct PresenceRecord {
        uint32_t when;  // ticks since startup
        uint8_t who;    // profile id
        uint8_t where;  // room id
    };

    /**
     * keeps track of a short history of presence events.
     * will be lazily updated to remove old entries: 
     *  - when new presence is detected
     *  - when getCurrentPresenceDescription() is called
     */
    static std::list<PresenceRecord> WhenWhoWhere;

    /**
     * Clears the WhenWhoWhere list from entries that have a time stamp older than
     * presence_time_out_s.
     */
    void removeOldRecords();

    /**
     * Processes a new profile-location combination:
     * - a new entry is placed in the WhenWhoWhere list, 
     * - previous entries with the same p-l combo are deleted
     * - the WhenWhoWhere list is purged of old entries
     */
    MutationType handleProfileLocationAdministration(uint8_t profile, uint8_t location);

    /**
     * Resolves the type of mutation from previous and next descriptions.
     */
    static MutationType getMutationType(
        std::optional<PresenceStateDescription> prevdescription, 
        std::optional<PresenceStateDescription> nextdescription);

    /**
     * Triggers a EVT_PROFILE_LOCATION event matching the given parameters.
     */
    void propagateMeshMessage(uint8_t profile, uint8_t location);

    /**
     * Triggers a EVT_PRESENCE_MUTATION event of the given type.
     */
    void triggerPresenceMutation(MutationType mutationtype);

    // out of order
    void print();
    
    stone_id_t _ownId = 0;

public:
    // register as event handler
    void init();

    /**
     * receive background messages indicating where users are,
     * record the time and place and update the current presence description
     * when necessary
     */
    virtual void handleEvent(event_t& evt) override;

    /**
     * Returns a simplified description of the current presence knowledge,
     * each bit in the description indicates if a person is in that room
     * or not.
     */
    static std::optional<PresenceStateDescription> getCurrentPresenceDescription();

};