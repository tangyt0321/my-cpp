#include <iostream>
#include <conio.h>
#include <easyx.h>
#include <math.h>

#include "player.h"
#include "enemy.h"

// void loadimage(
//     IMAGE *pDstImg,      // 保存图像的 IMAGE 对象指针
//     LPCTSTR pImgFile,    // 图片文件名
//     int nWidth = 0,      // 图片的拉伸宽度
//     int nHeight = 0,     // 图片的拉伸高度
//     bool bResize = false // 是否调整 IMAGE 的大小以适应图片
// );

int main()
{
    initgraph(1024, 800);

    // IMAGE bgImage;
    // loadimage(&bgImage, _T("./picture/background.png"));
    // putimage(0, 0, &bgImage);

    IMAGE p[2];
    loadimage(p , _T("./picture/player/player_.png"), 20, 36);
    loadimage(p+1, _T("./picture/player/player_r.png"), 20, 36);

    Player player;

    int style = 0, num = 0;

    player.draw(p+1);

    while (!_kbhit())
    {
        player.move(p, &style);
        player.attack(style, num);
        num--;
        Sleep(5);
    }

    return 0;
}