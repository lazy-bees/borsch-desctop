#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <memory>
#include <QStringList>

namespace Core {

class Launcher
{
public:
    explicit Launcher(int argc, char *argv[]);
    virtual ~Launcher() = default;

    static std::unique_ptr<Launcher> Create(int argc, char *argv[]);

    int exec();

private:
    int _argc = 0;
    char **_argv = nullptr;
    QStringList _arguments;
    QString _appDataPath;
    QString _workingPath;
    QString _openedUrl;
};

}
#endif // LAUNCHER_H
