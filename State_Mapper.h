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

// Our application states
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
    // Only allow exact string matches
    static AppState mapToAppState(const std::string& quicktelState);
    
    // Alternative enum mapping
    static AppState mapToAppState(QuicktelState quicktelState);
};

#endif // STATEMAPPER_H