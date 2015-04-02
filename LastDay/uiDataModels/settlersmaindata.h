#ifndef SETTLERSMAINDATA_H
#define SETTLERSMAINDATA_H
#include "QObject"

class SettlersMainData: public QObject
{
    Q_OBJECT
public:
    SettlersMainData(QObject* parent = 0);

    Q_PROPERTY(int Food READ getFood NOTIFY foodChanged)
    Q_PROPERTY(int Med READ getMed NOTIFY medChanged)
    Q_PROPERTY(int Pop READ getPop NOTIFY popChanged)


    int getFood() { return m_food; }
    int getMed() { return m_med; }
    int getPop() { return m_med; }


signals:
    void foodChanged();
    void medChanged();
    void popChanged();

public slots:
    void changeFood(int val);
    void changeMed(int val);


protected:
    int m_food;
    int m_med;
    int m_population;
};

#endif // SETTLERSMAINDATA_H
