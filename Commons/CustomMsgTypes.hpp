#include "commons.hpp"

namespace rt {
    enum class CustomMsgTypes : uint32_t
    {
        ServerAccept,
        ServerDeny,
        ServerPing,
        MessageAll,
        ServerMessage,
        SendData,
        
        SendEnnemies,
        SendBullets,
        SendBonus,

        AcceptedPlayer,
        AssignPlayerID,
        PlayerRegisterWithServer,
        PlayerUnregisterWithServer,
        AddPlayer,
        RemovePlayer,
        UpdatePlayer,
        PlayerIsShooting,
        PlayerUpdate,
        TimeBeforeGame,
    };
}