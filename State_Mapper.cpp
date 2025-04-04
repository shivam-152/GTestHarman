#include "StateMapper.h"
#include <unordered_map>

AppState StateMapper::mapToAppState(const std::string& quicktelState) {
    static const std::unordered_map<std::string, QuicktelState> stringToState = {
        {"SUCCEED", QuicktelState::SUCCEED},
        {"UPDATE", QuicktelState::UPDATE},
        {"WRITE_DONE", QuicktelState::WRITE_DONE},
        {"SYNC_PENDING", QuicktelState::SYNC_PENDING},
        {"BACKUP", QuicktelState::BACKUP},
        {"CANCEL", QuicktelState::CANCEL}
    };
    
    auto it = stringToState.find(quicktelState);
    return mapToAppState(it != stringToState.end() ? it->second : QuicktelState::UNKNOWN);
}

AppState StateMapper::mapToAppState(QuicktelState quicktelState) {
    switch (quicktelState) {
        case QuicktelState::SUCCEED:     return AppState::SUCCESS;
        case QuicktelState::UPDATE:      return AppState::UPDATE_IN_PROGRESS;
        case QuicktelState::WRITE_DONE:  return AppState::WRITE_COMPLETED;
        case QuicktelState::SYNC_PENDING:return AppState::SYNC_PENDING;
        case QuicktelState::BACKUP:      return AppState::BACKUP_IN_PROGRESS;
        case QuicktelState::CANCEL:      return AppState::OPERATION_CANCELLED;
        default:                        return AppState::INVALID_STATE;
    }
}