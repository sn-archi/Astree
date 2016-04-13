#ifndef DOCKOPTIMIZER_H
#define DOCKOPTIMIZER_H

#include <QDockWidget>

namespace Ui {
class DockOptimizer;
}

class OpticalDevice;

class DockOptimizer : public QDockWidget
{
    Q_OBJECT

public:
    explicit DockOptimizer(QWidget *parent = 0);
    ~DockOptimizer();

    void device_changed(OpticalDevice *pDevice, int iReason);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DockOptimizer *ui;
    OpticalDevice* _pDevice;

};

#endif // DOCKOPTIMIZER_H