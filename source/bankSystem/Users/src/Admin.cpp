#include "Admin.hpp"

Admin::Admin(const string& username, const string& password, int adminId)
    : User(username, password) {
  this->adminId = adminId;
}

int Admin::getAdminId() const { return adminId; }