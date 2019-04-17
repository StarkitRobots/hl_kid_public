#pragma once

#include <string>
#include <map>
#include <starkit_utils/sockets/udp_broadcast.h>
#include <starkit_team_play/team_play.h>
#include <RhIO.hpp>
#include "services/Service.h"

/**
 * TeamPlay
 *
 * UDP broadcast playing and robot state 
 * to others players and monitoring
 */
class TeamPlayService : public Service
{
    public:

        /**
         * Initialization
         */
        TeamPlayService();

        /**
         * Destructor
         */
        virtual ~TeamPlayService();

        /**
         * Return the robot teamplay id
         */
        int myId();
        
        /**
         * Access a teamplay info 
         * struct of current robot
         */
        const starkit_team_play::TeamPlayInfo& selfInfo() const;
        starkit_team_play::TeamPlayInfo& selfInfo();

        /**
         * Access to container to information 
         * on available other players
         */
        const std::map<int, starkit_team_play::TeamPlayInfo>& allInfo() const;

        /**
         * Read/Write network and 
         * update outputs
         */
        bool tick(double elapsed);

        /**
         * Is team play enabled ?
         */
        bool isEnabled();
    
 
        /**
         * TeamPlay radius
         */
        double teamRadius;

        /**
         * Extra radius for the referee
         */
        double refereeRadius;
        
    private:

        /**
         * RhIO Binding
         */
        RhIO::Bind* _bind;

        /**
         * UDPBroadcast instance
         */
        starkit_utils::UDPBroadcast* _broadcaster;

        /**
         * Current and other robots infos
         */
        starkit_team_play::TeamPlayInfo _selfInfo;
        std::map<int, starkit_team_play::TeamPlayInfo> _allInfo;

        /**
         * Send and check 
         * delay in seconds
         */
        double _t;
        
        /**
         * Enable or disable the teamplay
         */
        bool _isEnabled;

        /**
         * Broadcast period in seconds
         */
        double _broadcastPeriod;

        /**
         * Do message sending if needed
         */
        void messageSend();

        /**
         * Parse given message 
         * and update teamplay state
         */
        void processInfo(starkit_team_play::TeamPlayInfo info);

        /**
         * Is the placing aggressive or defensive?
         */
        double aggressivity;
        
        /**
         * RhIO team command
         */
        std::string cmdTeam();
};

