#include <qt6/QtWidgets/QWidget>
#include <qt6/QtWidgets/QHBoxLayout>
#include <qt6/QtWidgets/QLabel>
#include <qt6/QtCore/QTimer>

class Panel : public QWidget
{

public:
    Panel(QWidget *parent = nullptr);
    ~Panel();

    void MSG(QString message, int ms = 1000);

private:
    QLabel *m_msgLabel = new QLabel();
    QHBoxLayout *m_layout = new QHBoxLayout();
};
