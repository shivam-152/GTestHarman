#include "gtest/gtest.h"
#include "StateMapper.h"

TEST(StateMapperTest, ExactMatchMappings) {
    EXPECT_EQ(StateMapper::mapToAppState("SUCCEED"), AppState::SUCCESS);
    EXPECT_EQ(StateMapper::mapToAppState("UPDATE"), AppState::UPDATE_IN_PROGRESS);
    EXPECT_EQ(StateMapper::mapToAppState("WRITE_DONE"), AppState::WRITE_COMPLETED);
    EXPECT_EQ(StateMapper::mapToAppState("SYNC_PENDING"), AppState::SYNC_PENDING);
    EXPECT_EQ(StateMapper::mapToAppState("BACKUP"), AppState::BACKUP_IN_PROGRESS);
    EXPECT_EQ(StateMapper::mapToAppState("CANCEL"), AppState::OPERATION_CANCELLED);
}

TEST(StateMapperTest, FailedMappings) {
    // Case variations should fail
    EXPECT_EQ(StateMapper::mapToAppState("succeed"), AppState::INVALID_STATE);
    EXPECT_EQ(StateMapper::mapToAppState("Write_Done"), AppState::INVALID_STATE);
    
    // Invalid states
    EXPECT_EQ(StateMapper::mapToAppState(""), AppState::INVALID_STATE);
    EXPECT_EQ(StateMapper::mapToAppState("INVALID"), AppState::INVALID_STATE);
    EXPECT_EQ(StateMapper::mapToAppState("SUCEED"), AppState::INVALID_STATE);
    EXPECT_EQ(StateMapper::mapToAppState("123"), AppState::INVALID_STATE);
}

TEST(StateMapperTest, DirectEnumMapping) {
    EXPECT_EQ(StateMapper::mapToAppState(QuicktelState::SUCCEED), AppState::SUCCESS);
    EXPECT_EQ(StateMapper::mapToAppState(QuicktelState::UPDATE), AppState::UPDATE_IN_PROGRESS);
    EXPECT_EQ(StateMapper::mapToAppState(QuicktelState::UNKNOWN), AppState::INVALID_STATE);
}

// Additional test cases

TEST(StateMapperTest, MixedCaseMappings) {
    EXPECT_EQ(StateMapper::mapToAppState("sUcCeEd"), AppState::INVALID_STATE);
    EXPECT_EQ(StateMapper::mapToAppState("UpDaTe"), AppState::INVALID_STATE);
}

TEST(StateMapperTest, WhitespaceMappings) {
    EXPECT_EQ(StateMapper::mapToAppState(" SUCCEED "), AppState::INVALID_STATE);
    EXPECT_EQ(StateMapper::mapToAppState("UPDATE "), AppState::INVALID_STATE);
}

TEST(StateMapperTest, SpecialCharacterMappings) {
    EXPECT_EQ(StateMapper::mapToAppState("SUCCEED!"), AppState::INVALID_STATE);
    EXPECT_EQ(StateMapper::mapToAppState("UPDATE@"), AppState::INVALID_STATE);
}

TEST(StateMapperTest, EnumMappingWithInvalidState) {
    EXPECT_EQ(StateMapper::mapToAppState(QuicktelState::UNKNOWN), AppState::INVALID_STATE);
    EXPECT_EQ(StateMapper::mapToAppState(static_cast<QuicktelState>(999)), AppState::INVALID_STATE); // Invalid enum value
}
