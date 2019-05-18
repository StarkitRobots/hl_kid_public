#pragma once

#include <starkit_utils/timing/elapse_tick.h>
#include "scheduler/Helpers.h"

/**
 * Service
 *
 * Base class for service instance
 */
class Service : public Helpers, public starkit_utils::ElapseTick
{
    public:

        /**
         * Implement empty ElapseTick tick
         */
        virtual bool tick(double elapsed) override;
};

