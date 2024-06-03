#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>


//�萔
#define SCREEN_X 800
#define SCREEN_Y 600
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS 10
#define CIRCLE_RADIUS_MAX 100

//�ϐ�
typedef struct circle
{
    int posX;
    int posY;
    int radius;
}circle;

//�Q�[���v���O
bool enterPressedLastFrame = false;//�G���^�[�L�[�������ꂽ���ǂ����̃t���O
bool gameStartFlag = false;//�Q�[���J�n�t���O
bool circleGenerationFlag = true;//�~�̐����t���O
bool gameEndFlag = true;//�Q�[���I���t���O

//�Q�[���J�E���g
int enterPressCount;
//�\���̂�ϐ��ɂ���
circle circle1;
//�~�̍ő�ʐ�
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;

//���C���֐�
int Winmain(HINSTANCE, HINSTANCE, LPSTR, int)//WIndows�̃��C���œ�����
{
    //��{�ݒ�
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetMainWindowText("�^�C�~���O�Q�[��");
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
    SetGraphMode(800, 600, 32);//��ʂ̑傫��

    //Dxlib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N������I��

        return -1;
    }
    //�F�̎w��
    int circleColor = GetColor(128, 128, 128);
    //�~�̕`��
    circle1.posX = CIRCLE_POS_X;
    circle1.posY = CIRCLE_POS_Y;
    circle1.radius = CIRCLE_RADIUS;

    //�Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClearDrawScreen();

        DrawCircle(circle1.posX, circle1.posY, circle1.radius, GetColor(0, 0, 255), TRUE);
        if (CheckHitKey(KEY_INPUT_UP))
        {
            circle1.radius += 1;
        }


    }
    //DxLib�I������
    DxLib_End();

    return 0;
}