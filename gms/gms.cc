/*
 * Copyright (C) 2015 Cloudius Systems, Ltd.
 */

// Used to ensure that all .hh files build, as well as a place to put
// out-of-line implementations.

#include "gms/gossiper.hh"
#include "gms/application_state.hh"
#include "gms/version_generator.hh"
#include "gms/versioned_value.hh"
#include "gms/gossip_digest.hh"
#include "gms/gossip_digest_syn.hh"
#include "gms/gossip_digest_ack.hh"
#include "gms/gossip_digest_ack2.hh"
#include "gms/heart_beat_state.hh"
#include "gms/token_serializer.hh"
#include "gms/i_endpoint_state_change_subscriber.hh"
#include "gms/i_failure_detection_event_listener.hh"
#include "gms/failure_detector.hh"

#include "core/distributed.hh"
namespace gms {
distributed<gossiper> _the_gossiper;
distributed<failure_detector> _the_failure_detector;

std::ostream& operator<<(std::ostream& os, const gossip_digest_syn& syn) {
    os << "cluster_id:" << syn._cluster_id << ",partioner:" << syn._partioner << ",";
    os << "digests:{";
    for (auto& d : syn._digests) {
        os << d << " ";
    }
    return os << "}";
}

}
