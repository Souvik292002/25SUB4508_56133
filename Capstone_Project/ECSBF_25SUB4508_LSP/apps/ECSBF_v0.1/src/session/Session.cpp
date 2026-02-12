#include "Session.h"

/* ---------------- CONSTRUCTOR ---------------- */
Session::Session(const std::string& sid, const std::string& nid)
    : sessionId(sid), nodeId(nid), active(true) {}

/* ---------------- GET NODE ID ---------------- */
std::string Session::getNodeId() const {
    return nodeId;
}

/* ---------------- SESSION STATE ---------------- */
bool Session::isActive() const {
    return active;
}

void Session::invalidate() {
    active = false;
}

/* ---------------- RESTORE SESSION (FR-04) ---------------- */
void Session::restore() {
    active = true;
}
