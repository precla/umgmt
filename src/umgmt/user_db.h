/**
 * @file user_db.h
 * @brief API for the user database abstract data type.
 */
#ifndef UMGMT_USER_DB_H
#define UMGMT_USER_DB_H

#include "types.h"

#include <pwd.h>

/**
 * Allocate new user database.
 *
 * @return New allocated database.
 *
 */
um_user_db_t *um_user_db_new(void);

/**
 * Load user database from the system.
 *
 * @param db Database to load.
 *
 * @return Error code - 0 on success.
 *
 */
int um_user_db_load(um_user_db_t *db);

/**
 * Store user database to the system.
 *
 * @param db Database to store.
 *
 * @return Error code - 0 on success.
 *
 */
int um_user_db_store(um_user_db_t *db);

/**
 * Return the new UID which can be used for a new user.
 *
 * @param db Database to use.
 *
 * @return New UID.
 *
 */
uid_t um_user_db_get_new_uid(um_user_db_t *db);

/**
 * Return the new GID which can be used for a new user.
 *
 * @param db Database to use.
 *
 * @return New GID.
 *
 */
gid_t um_user_db_get_new_gid(um_user_db_t *db);

/**
 * Add a new user to the database.
 * User will be handled by the database from this point on - do not free user data after adding user to the database.
 *
 * @param db Database to use.
 * @param user_name User to search for.
 *
 * @return Abstract user type - NULL if not found.
 *
 */
int um_user_db_add_user(um_user_db_t *db, um_user_t *user);

/**
 * Get the user from the database.
 *
 * @param db Database to use.
 * @param user_name User to search for.
 *
 * @return Abstract user type - NULL if not found.
 *
 */
um_user_t *um_user_db_get_user(um_user_db_t *db, const char *user_name);

/**
 * Delete user from the database.
 *
 * @param db Database to use.
 * @param user_name User to search for.
 *
 * @return Error code - 0 on success.
 *
 */
int um_user_db_delete_user(um_user_db_t *db, const char *user_name);

/**
 * Get users list head.
 *
 * @param db Database to use.
 *
 * @return Users list head.
 *
 */
const um_user_element_t *um_user_db_get_user_list_head(const um_user_db_t *db);

/**
 * Free user database data.
 *
 * @param db User database to free.
 *
 */
void um_user_db_free(um_user_db_t *db);

#endif // UMGMT_USER_DB_H