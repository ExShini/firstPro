#include "testroom.h"

testRoom::testRoom():
    room(8, 14)
{
    //dirty porn =)
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {

            if (i == 0 || i == m_height - 1 || j == 0 || j == m_width - 1)
            {
                addObject(t_Wall,j ,i, NODIR);
            }
            else
            {
                addObject(t_Floor,j ,i, NODIR);
            }
        }
    }

    addObject(t_MedBox,1 ,2, RIGHT);
    addObject(t_MedBox,1 ,3, RIGHT);
    addObject(t_MedBox,6 ,8, LEFT);
    addObject(t_MedBox,6 ,9, LEFT);
    addObject(t_MedBox,6 ,10, LEFT);


}


testRoom2::testRoom2():
    room(12, 12)
{
    for (int i = m_height/2 - 4; i < m_height/2 + 4; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            addObject(t_Floor,j ,i, NODIR);
        }
    }

    for (int i = m_width/2 - 4; i < m_width/2 + 4; i++)
    {
        for (int j = 0; j < m_height; j++)
        {
            addObject(t_Floor,i ,j, NODIR);
        }
    }


    addObject(t_SF,4 ,4, DOWN);
    addObject(t_SF,5 ,4, UP);

}
