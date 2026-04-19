#include <3ds.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

class SocketResult
{
public:
    SocketResult(const char *info, bool success) :
        mInfo(info), mSuccess(success) {}

    const char *info() const
    {
        return mInfo;
    }

    bool success() const
    {
        return mSuccess;
    }

private:
    const char *mInfo;
    bool        mSuccess;
};

class Socket
{
public:
    Socket(const char *ip, short port) :
        mHandle(-1), mConnected(false)
    {
        if (!mSocketInitialized) {
            init();
            mSocketInitialized = true;
        }

        mHandle = socket(AF_INET, SOCK_STREAM, 0);

        if (mHandle >= 0) {
            sockaddr_in in {};

            in.sin_family      = AF_INET;
            in.sin_addr.s_addr = inet_addr(ip);
            in.sin_port        = htons(port);

            if (::connect(mHandle, (sockaddr *)&in, sizeof(in)) == 0)
                mConnected = true;
        }
    }

    ~Socket()
    {
        if (mHandle >= 0)
            closesocket(mHandle);
    }

    bool isConnected()
    {
        return mConnected;
    }

    SocketResult send(std::string msg)
    {
        if (!mConnected)
            return SocketResult("Not connected", false);

        msg += '\n';

        if (::send(mHandle, msg.c_str(), msg.length(), 0) > 0)
            return SocketResult("Success", true);

        return SocketResult("Failed", false);
    }

private:
    static inline bool mSocketInitialized;

    static void init()
    {
        void *mem = linearAlloc(0x100000);
        memset(mem, 0, 0x100000);
        socInit((u32 *)mem, 0x100000);
    }

private:
    bool   mConnected;
    Handle mHandle;
};