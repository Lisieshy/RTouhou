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

        AcceptedPlayer,
        AssignPlayerID,
        PlayerRegisterWithServer,
        PlayerUnregisterWithServer,
        AddPlayer,
        RemovePlayer,
        UpdatePlayer,
    };
}