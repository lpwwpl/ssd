#ifndef MAIN_H
#define MAIN_H

#include "Listing.h"
#include "CategoryHierarchy.h"
#include "Group.h"

#define BACKLOG 11
#define REQ_MAX 8192

extern CategoryHierarchy categories;
extern Listing advertisements;
extern Group users;

extern string active_user;

extern int category_counter;
extern int advertisement_counter;

extern bool create_verified;
extern bool login_failed;

#endif
