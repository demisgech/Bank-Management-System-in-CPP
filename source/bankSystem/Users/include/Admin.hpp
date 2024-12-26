#ifndef ADMIN__HPP
#define ADMIN__HPP

#include "User.hpp"

class Admin : public User {
 private:
  int adminId;

 public:
  Admin(const string& username, const string& password, int adminId);
  int getAdminId() const;
};

#endif