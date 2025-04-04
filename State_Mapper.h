#ifndef STATEMAPPER_H
#define STATEMAPPER_H

#include <string>

enum class QuicktelState {
    SUCCEED,      
    UPDATE,
    WRITE_DONE,   
    SYNC_PENDING, 
    BACKUP,
    CANCEL,
    UNKNOWN
};


enum class AppState {
    SUCCESS,
    UPDATE_IN_PROGRESS,
    WRITE_COMPLETED,
    SYNC_PENDING,
    BACKUP_IN_PROGRESS,
    OPERATION_CANCELLED,
    INVALID_STATE
};

class StateMapper {
public:

    static AppState mapToAppState(const std::string& quicktelState);
    
    
    static AppState mapToAppState(QuicktelState quicktelState);
};

#endif 
