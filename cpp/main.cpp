#include "src/mainwindow.hpp"

bool isRunningAsAdmin() {
    BOOL isAdmin = FALSE;
    PSID adminGroup;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;
    if (AllocateAndInitializeSid(&ntAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminGroup)) {
        CheckTokenMembership(NULL, adminGroup, &isAdmin);
        FreeSid(adminGroup);
    }
    return isAdmin;
}

void restartAsAdmin() {
    wchar_t path[MAX_PATH];
    GetModuleFileNameW(NULL, path, MAX_PATH);
    ShellExecuteW(NULL, L"runas", path, NULL, NULL, SW_SHOWNORMAL);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setOrganizationName("Vadeev");
    QApplication::setApplicationName("Gayshit-Infarct-Killer");

    if (!isRunningAsAdmin()) {
        if (QMessageBox::question(nullptr, QObject::tr("Administrator rights required"),
                                QObject::tr("The application requires administrator rights. Restart?"),
                                QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
            restartAsAdmin();
            return 0;
        }
    }

    MainWindow w;

    w.setWindowTitle(QObject::tr("GIK"));
    w.show();

    return app.exec();
}