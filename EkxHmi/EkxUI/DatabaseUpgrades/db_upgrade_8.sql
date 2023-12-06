drop table if exists `notification_types`;

CREATE TABLE IF NOT EXISTS "notification_types" (
	"notification_type_id"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
	"notification_name"	VARCHAR(30) NOT NULL UNIQUE,
	"description"	VARCHAR(255),
	"notification_class_id"	INTEGER NOT NULL,
	"recover_action"	INTEGER,
	"short_info"	VARCHAR(50),
	"long_info"	VARCHAR(255)
);

REPLACE INTO "notification_types" ("notification_type_id","notification_name","description","notification_class_id","recover_action","short_info","long_info") VALUES (1,'GRINDER_CHAMBER_OPENED','The grinder chamber is opened. Motor cannot be actuated. No grind action possible.',3,0,'Open Grinder Chamber','Grinder chamber\nopened!'),
 (2,'HOPPER_DISMOUNTED','The bean hopper has been dismounted. Motor cannot be actuated. No grind action possible.',3,0,'No Bean Hopper','Bean hopper\ndismounted!'),
 (3,'ESP_INTERFACE_FAILED','Communication between HMI and WiFi board is interrupted. No grind actions possible. WebServer is not available.',3,1,'WiFi Comm Failed','WiFi board\ncommunication\nfailed!'),
 (4,'MCU_INTERFACE_FAILED','Communication between HMI board and motor control unit is interrupted. No grind actions possible. ',3,1,'MCU Comm Failed','MCU board\ncommunication\nfailed!'),
 (5,'DDD1_FAILED','DDD 1 (coarse) sensor is not available or sensor data invalid. DDD display is invalid and AGSA deactivated.',3,0,'DDD 1 Failed!','DDD 1 sensor\nfailed!'),
 (6,'AGSA_FAILED_BLOCKAGE','AGSA motor drive has been stopped because of a blockage within drive system. Try to repeat action.',2,0,'AGSA Blockage','AGSA driver\nfailed!\nBlockage!'),
 (7,'CHANGE_DISCS_INFO','Grinding discs life time has been exceeded. Exchange grinding discs and reset counter.',1,0,'Grinding Discs','Change grinding\ndiscs!'),
 (8,'START_GRIND_FAILED','Grinding motor hasn''t started although commanded to do so. Maybe grinding motor is blocked or communication disturbed?',3,0,'Start Grind Failed','Start grind\nfailed!'),
 (9,'STOP_GRIND_FAILED','Grinding motor hasn''t stopped although commanded to do so. Maybe communication to motor control unit disturbed?',3,0,'Stop Grind Failed','Stop grind\nfailed!'),
 (10,'SYSTEM_TIME_LOST','System clock has been resetted due to a long period power off. Please set the current date and time within system settings menu. The system provides a clock powering of max. 2 weeks.',2,1,'System Time Lost','System time\nlost, please\nset manually!'),
 (11,'DDD2_FAILED','DDD 2 (fine) sensor is not available or sensor data invalid. DDD display is invalid and AGSA deactivated.',3,0,'DDD 2 Failed!','DDD 2 sensor\nfailed!'),
 (12,'AGSA_FAILED_TIMEOUT','AGSA motor drive has been stopped by timeout, because a complete AGSA move reaches timeout. Try to repeat action.',2,0,'AGSA Timeout','AGSA driver\nfailed!\nTimeout!'),
 (13,'SW_UPDATE_UPLOAD_FAILED','Upload of software update package failed. Try to repeat SW update.',2,0,'SW Update Failed','Upload of update\npackage failed!'),
 (14,'SW_UPDATE_PACKAGE_FAILED','Consitency check of SW update package failed. Try to repeat SW update or validate package source.',3,0,'SW Update Failed','File is no valid\nupdate package!'),
 (15,'SW_UPDATE_PACKAGE_NO_UPGRADE','Software update package rejected. Package contains no upgrade version.',2,0,'SW Update Failed','Update package\nis no upgrade!'),
 (16,'SW_UPDATE_UNPACK_ROOTFS_FAILED','Software update failed. Unpacking image #1 of 2 failed. Try to repeat SW update.',3,0,'SW Update Failed','Unpacking image\n#1 failed!'),
 (17,'SW_UPDATE_UNPACK_APPLICATION_FAILED','Software update failed. Unpacking image #2 of 2 failed. Try to repeat SW update.',3,0,'SW Update Failed','Unpacking image\n#2 failed!'),
 (18,'STARTUP_ROOTFS_VERSION_FAILED','Check of core system version information failed. Repeat SW update to recover.',3,0,'Startup Failed','Startup check of\nimage #1 failed!'),
 (19,'LOAD_SETTINGS_FAILED','Loading of configuration data failed. Try to reconfigure the grinder.',3,0,'Load Settings Failed','Load settings\nfailed!'),
 (20,'SW_UPDATE_MCU_UPDATE_FAILED','Software update of MCU failed. System will be rolled back to previous state. Try to repeat SW update.',3,0,'SW Update Failed','Update of MCU\nboard failed!'),
 (21,'SW_UPDATE_ESP_UPDATE_FAILED','Software update of WiFi board failed. System will be rolled back to previous state. Try to repeat SW update.',3,0,'SW Update Failed','Update of WiFi\nboard failed!'),
 (22,'SW_UPDATE_UPLOAD_ABORTED','Upload of software update package has been aborted by user. Try to repeat SW update.',2,0,'SW Update Failed','Upload aborted\nby user!'),
 (23,'SW_UPDATE_ROLLED_BACK','System has been rolled back to previous state after failed SW update. Try to repeat SW update.',1,0,'Rollback','Perform rollback\nafter failed\nSW update!'),
 (24,'SW_UPDATE_ROLLBACK_APP_FAILED','Rollback of image #2 of 2 to previous state failed after failed SW update. System is probably inconsistent. Try to repeat SW update.',3,0,'Rollback Failed','Rollback of\nimage #2 failed!'),
 (25,'SW_UPDATE_ROLLBACK_ROOTFS_FAILED','Rollback of image #1 of 2 to previous state failed after failed SW update. System is probably inconsistent. Try to repeat SW update.',3,0,'Rollback Failed','Rollback of\nimage #1 failed!'),
 (26,'SW_UPDATE_COMPLETED','Software update has been successfully completed.',1,0,'SW Update Completed','Software update\nsuccessfully\ncompleted!'),
 (27,'SW_UPDATE_ROLLBACK_FAILED','Rollback to previous system state failed after failed SW update. Try to repeat SW update.',3,0,'Rollback Failed','Rollback after\nSW update failed!'),
 (28,'STARTUP_ESP_CHECK_VERSION_TIMEOUT','Read of WiFi board version information timed out.',3,0,'Startup Failed','WiFi board SW\nversion check failed!\nTimeout!'),
 (29,'STARTUP_MCU_CHECK_VERSION_TIMEOUT','Read of MCU version information timed out.',3,0,'Startup Failed','MCU board SW\nversion check failed!\nTimeout!'),
 (30,'SW_UPDATE_ESP_UPDATE_TIMEOUT','Software update of WiFi board timed out. System will be rolled back to previous state. Try to repeat SW update.',3,0,'SW Update Failed','Timeout while\nupdating WiFi board!'),
 (31,'SW_UPDATE_MCU_UPDATE_TIMEOUT','Software update of MCU timed out. System will be rolled back to previous state. Try to repeat SW update.',3,0,'SW Update Failed','Timeout while\nupdating MCU board!'),
 (32,'SW_UPDATE_ESP_VALIDATE_VERSION_TIMEOUT','Validation of WiFi board version timed out after software update. System will be rolled back to previous state. Try to repeat SW update.',3,0,'SW Update Failed','Timeout while\nvalidating WiFi board\nSW version!'),
 (33,'SW_UPDATE_MCU_VALIDATE_VERSION_TIMEOUT','Validation of MCU version timed out after software update. System will be rolled back to previous state. Try to repeat SW update.',3,0,'SW Update Failed','Timeout while\nvalidating MCU board\nSW version!'),
 (34,'AGSA_FAILED_NO_DDD','AGSA motor drive has been stopped because at least one DDD sensor is failed.',3,0,'AGSA No DDD','AGSA driver\nfailed!\nNo DDD!'),
 (35,'ROLLBACK_STARTUP_FAILED','Rollback to previous system state failed after a failed SW update. Try to repeat SW update.',3,0,'Startup Failed','Rollback startup\nfailed!'),
 (36,'SW_UPDATE_STARTUP_FAILED','System startup failed due to previous error. Maybe restart grinder.',1,0,'Startup Failed','System startup\nfailed due to\nprevious errors!'),
 (37,'SW_UPDATE_MCU_VALIDATE_VERSION_FAILED','Validation of MCU version failed after software update. System will be rolled back to previous state. Try to repeat SW update.',3,0,'SW Update Failed','MCU board SW\nversion validation\nfailed!'),
 (38,'SW_UPDATE_ESP_VALIDATE_VERSION_FAILED','Validation of WiFi board version failed after software update. System will be rolled back to previous state. Try to repeat SW update.',3,0,'SW Update Failed','WiFi board SW\nversion validation\nfailed!'),
 (39,'DB_UPDATE_FAILED','Internal database error. Database update failed.',3,0,'DB Update Failed','Database update\nfailed!'),
 (40,'SAVE_SETTINGS_FAILED','Save of configuration file failed. Changes are lost.',3,1,'Save Settings Failed','Save settings\nfailed!'),
 (41,'DB_QUERY_STATISTICS_RESULT','Internal database error. Query of statistics database result failed.',2,0,'DB Query Stat. Failed','Database access\nquery statistics\nresult failed!'),
 (42,'DB_CHANGE_RECIPE','Internal database error. Inserting a recipe change failed. ',2,0,'DB Chg.Recipe Failed','Database access\nchange recipe\nfailed!'),
 (43,'DB_INSERT_RECIPE','Internal database error. Insertion of a new recipe failed.',2,0,'DB Ins.Recipe Failed','Database access\ninsert recipe\nfailed!'),
 (44,'DB_ADD_GRIND','Internal database error. Adding a grind result into database failed.',2,0,'DB Add Grind Failed','Database access\nadd grind\nfailed!'),
 (45,'DB_ADD_DELTA_TO_COUNTER','Internal database error. Incrementing of a counter has been failed.',2,0,'DB Delta.Cnt. Failed','Database access\ndelta to counter\nfailed!'),
 (46,'DB_RESET_COUNTER','Internal database error. Reset of counters failed.',2,0,'DB Reset.Cnt. Failed','Database access\nreset counter\nfailed!'),
 (47,'DB_QUERY_COUNTER','Internal database error. Database request for a counter failed.',2,0,'DB Delta.Cnt. Failed','Database access\nquery counter\nfailed!'),
 (48,'DB_CREATE_NEW_SCHEME','A new database scheme has been successfully activated. ',1,0,'Create New DB','New database\ncreated!'),
 (49,'DB_CREATE_NEW_SCHEME_FAILED','Internal database error. Buildup of a new database failed, the scheme couldn''t be applied.',3,0,'Create New DB Failed','Create new\ndatabase\nfailed!'),
 (50,'MAIN_STATE_FILE_CORRUPTED','Internal state file corrupted. Maybe inconsistent grinder behaviour.',3,0,'State File Corrupt','Main state file\ncorrupted!'),
 (51,'SW_UPDATE_STATE_FILE_CORRUPTED','Internal SW update state file corrupted. System state reset to normal.',3,0,'State File Corrupt','Software update\nstate file\ncorrupted!'),
 (52,'MAIN_STATE_FILE_READ_FAILED','Internal state file couldn''t be read and will be resetted. Maybe inconsistent grinder behaviour.',3,0,'State File Read','Main state file\nread failed!'),
 (53,'MAIN_STATE_FILE_WRITE_FAILED','Internal state file couldn''t be written and will be resetted. Maybe inconsistent grinder behaviour.',3,0,'State File Write','Main state file\nwrite failed!'),
 (54,'SW_UPDATE_STATE_FILE_WRITE','Internal SW update state file couldn''t be written. System state reset to normal.',3,0,'State File Write','Software update\nstate file\nwrite failed!'),
 (55,'PDU_INSTALLED_AFTER_ABSENCE','PDU has been automatically detected as installed after being absent.',1,0,'PDU Installed','PDU installed\nafter being absent!'),
 (56,'PDU_UNINSTALLED_AFTER_PRESENCE','PDU has been automatically detected as not installed after being present.',1,0,'PDU Unistalled','PDU uninstalled\nafter being present!');

REPLACE INTO `settings` (`key`, `value`) VALUES ( 'Version', '8' );
