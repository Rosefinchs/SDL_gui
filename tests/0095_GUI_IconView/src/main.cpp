#include <SDL.h>
#include <iostream>
#if defined(WIN32)
#include "..\_VisualC\WinApp\WinApp\resource.h"
#include <SDL_syswm.h>
#endif
#include "SDL_gui.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

using namespace std;

char title[] = "SDL_gui App";
int expectedWidth = 960;
int expectedHeight = 540;

static GUI_View *topView;

int main(int argc, char *argv[]) {
    SDL_Log( "Hello, World!\n" );
    SDL_SetHint(SDL_HINT_ORIENTATIONS, "LandscapeLeft LandscapeRight");

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL\n");
        SDL_LogError( SDL_LOG_CATEGORY_ERROR, "Hello, World!\n" );
        exit(1);
    }
    
    if (TTF_Init() != 0) {
        GUI_Log("TTF_Init failed.");
        SDL_Quit();
        return 1;
    }

    // Create Window
    SDL_Log("request: %d %d\n", expectedWidth, expectedHeight);
    GUI_Init("GUI_TextView", expectedWidth, expectedHeight );
    
    topView = GUI_createTopView("TopView", 0, 0, -1, -1);
    topView->setMargin(10, 10, 10, 10);
    topView->setPadding(5, 5, 5, 5);
    
    GUI_View *vMain = GUI_View::create( topView, "Main1", 0, 0, 500, 270 );
    vMain->setBackgroundColor( cDarkGrey );
    vMain->setMargin( 5, 5, 5, 5 );
    vMain->setPadding( 5, 5, 5, 5 );
    vMain->dragable = true;
    
    GUI_IconView *vRed = GUI_IconView::create( vMain, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 150, 70 );
    vRed->setBackgroundColor( cRed );
    vRed->dragable = true;
    vRed->setContentAlign( GUI_ALIGN_TOP | GUI_ALIGN_LEFT );
    vRed->setMargin( 5, 5, 5, 5 );
    vRed->setPadding( 5, 5, 5, 5 );
    
    GUI_IconView *vGreen = GUI_IconView::create( vMain, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 150, 70 );
    vGreen->setBackgroundColor( cGreen );
    vGreen->dragable = true;
    vGreen->setAlign( GUI_ALIGN_TOP | GUI_ALIGN_CENTER );
    vGreen->setContentAlign( GUI_ALIGN_TOP | GUI_ALIGN_CENTER );
    vGreen->setMargin( 5, 5, 5, 5 );
    vGreen->setPadding( 5, 5, 5, 5 );

    GUI_IconView *vBlue = GUI_IconView::create( vMain, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 150, 70 );
    vBlue->setBackgroundColor( cBlue );
    vBlue->dragable = true;
    vBlue->setAlign( GUI_ALIGN_TOP | GUI_ALIGN_RIGHT );
    vBlue->setContentAlign( GUI_ALIGN_TOP | GUI_ALIGN_RIGHT );
    vBlue->setMargin( 5, 5, 5, 5 );
    vBlue->setPadding( 5, 5, 5, 5 );

    GUI_IconView *vRed2 = GUI_IconView::create( vMain, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 150, 70 );
    vRed2->setBackgroundColor( cRed );
    vRed2->dragable = true;
    vRed2->setAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_LEFT );
    vRed2->setContentAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_LEFT );
    vRed2->setMargin( 5, 5, 5, 5 );
    vRed2->setPadding( 5, 5, 5, 5 );

    GUI_IconView *vGreen2 = GUI_IconView::create( vMain, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 150, 70 );
    vGreen2->setBackgroundColor( cGreen );
    vGreen2->dragable = true;
    vGreen2->setAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_CENTER );
    vGreen2->setContentAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_CENTER );
    vGreen2->setMargin( 5, 5, 5, 5 );
    vGreen2->setPadding( 5, 5, 5, 5 );

    GUI_IconView *vBlue2 = GUI_IconView::create( vMain, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 150, 70 );
    vBlue2->setBackgroundColor( cBlue );
    vBlue2->dragable = true;
    vBlue2->setAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_RIGHT );
    vBlue2->setContentAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_RIGHT );
    vBlue2->setMargin( 5, 5, 5, 5 );
    vBlue2->setPadding( 5, 5, 5, 5 );

    GUI_IconView *vRed3 = GUI_IconView::create( vMain, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 150, 70 );
    vRed3->setBackgroundColor( cRed );
    vRed3->dragable = true;
    vRed3->setAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_LEFT );
    vRed3->setContentAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_LEFT );
    vRed3->setMargin( 5, 5, 5, 5 );
    vRed3->setPadding( 5, 5, 5, 5 );

    GUI_IconView *vGreen3 = GUI_IconView::create( vMain, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 150, 70 );
    vGreen3->setBackgroundColor( cGreen );
    vGreen3->dragable = true;
    vGreen3->setAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_CENTER );
    vGreen3->setContentAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_CENTER );
    vGreen3->setMargin( 5, 5, 5, 5 );
    vGreen3->setPadding( 5, 5, 5, 5 );

    GUI_IconView *vBlue3 = GUI_IconView::create( vMain, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 150, 70 );
    vBlue3->setBackgroundColor( cBlue );
    vBlue3->dragable = true;
    vBlue3->setAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_RIGHT );
    vBlue3->setContentAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_RIGHT );
    vBlue3->setMargin( 5, 5, 5, 5 );
    vBlue3->setPadding( 5, 5, 5, 5 );

    GUI_View *vGrey = GUI_View::create( topView, "Gray", 520, 0, -1, -1 );
    vGrey->setBackgroundColor( cGrey );
    vGrey->setMargin( 5, 5, 5, 5 );
    vGrey->setPadding( 5, 5, 5, 5 );
    vGrey->dragable = true;
  
    GUI_IconView *vRedX = GUI_IconView::create( vGrey, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 0, 0 );
    vRedX->setBackgroundColor( cRed );
    vRedX->dragable = true;
    vRedX->setContentAlign( GUI_ALIGN_TOP | GUI_ALIGN_LEFT );
    vRedX->setMargin( 5, 5, 5, 5 );
    vRedX->setPadding( 5, 5, 5, 5 );
    
    GUI_IconView *vGreenX = GUI_IconView::create( vGrey, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 0, 0 );
    vGreenX->setBackgroundColor( cGreen );
    vGreenX->dragable = true;
    vGreenX->setAlign( GUI_ALIGN_TOP | GUI_ALIGN_CENTER );
    vGreenX->setContentAlign( GUI_ALIGN_TOP | GUI_ALIGN_CENTER );
    vGreenX->setMargin( 5, 5, 5, 5 );
    vGreenX->setPadding( 5, 5, 5, 5 );
    
    GUI_IconView *vBlueX = GUI_IconView::create( vGrey, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 0, 0 );
    vBlueX->setBackgroundColor( cBlue );
    vBlueX->dragable = true;
    vBlueX->setAlign( GUI_ALIGN_TOP | GUI_ALIGN_RIGHT );
    vBlueX->setContentAlign( GUI_ALIGN_TOP | GUI_ALIGN_RIGHT );
    vBlueX->setMargin( 5, 5, 5, 5 );
    vBlueX->setPadding( 5, 5, 5, 5 );
    
    GUI_IconView *vRedX2 = GUI_IconView::create( vGrey, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 0, 0 );
    vRedX2->setBackgroundColor( cRed );
    vRedX2->dragable = true;
    vRedX2->setAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_LEFT );
    vRedX2->setContentAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_LEFT );
    vRedX2->setMargin( 5, 5, 5, 5 );
    vRedX2->setPadding( 5, 5, 5, 5 );
    
    GUI_IconView *vGreenX2 = GUI_IconView::create( vGrey, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 0, 0 );
    vGreenX2->setBackgroundColor( cGreen );
    vGreenX2->dragable = true;
    vGreenX2->setAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_CENTER );
    vGreenX2->setContentAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_CENTER );
    vGreenX2->setMargin( 5, 5, 5, 5 );
    vGreenX2->setPadding( 5, 5, 5, 5 );
    
    GUI_IconView *vBlueX2 = GUI_IconView::create( vGrey, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 0, 0 );
    vBlueX2->setBackgroundColor( cBlue );
    vBlueX2->dragable = true;
    vBlueX2->setAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_RIGHT );
    vBlueX2->setContentAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_RIGHT );
    vBlueX2->setMargin( 5, 5, 5, 5 );
    vBlueX2->setPadding( 5, 5, 5, 5 );
    
    GUI_IconView *vRedX3 = GUI_IconView::create( vGrey, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 0, 0 );
    vRedX3->setBackgroundColor( cRed );
    vRedX3->dragable = true;
    vRedX3->setAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_LEFT );
    vRedX3->setContentAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_LEFT );
    vRedX3->setMargin( 5, 5, 5, 5 );
    vRedX3->setPadding( 5, 5, 5, 5 );
    
    GUI_IconView *vGreenX3 = GUI_IconView::create( vGrey, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 0, 0 );
    vGreenX3->setBackgroundColor( cGreen );
    vGreenX3->dragable = true;
    vGreenX3->setAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_CENTER );
    vGreenX3->setContentAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_CENTER );
    vGreenX3->setMargin( 5, 5, 5, 5 );
    vGreenX3->setPadding( 5, 5, 5, 5 );
    
    GUI_IconView *vBlueX3 = GUI_IconView::create( vGrey, kIcon_solid_sun, "fa-regular-400.ttf", 16, 0, 0, 0, 0 );
    vBlueX3->setBackgroundColor( cBlue );
    vBlueX3->dragable = true;
    vBlueX3->setAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_RIGHT );
    vBlueX3->setContentAlign( GUI_ALIGN_BOTTOM | GUI_ALIGN_RIGHT );
    vBlueX3->setMargin( 5, 5, 5, 5 );
    vBlueX3->setPadding( 5, 5, 5, 5 );
    
    
    GUI_View *vGrey2 = GUI_View::create( topView, "Gray", 0, 290, 500, -1 );
    vGrey2->setBackgroundColor( cGrey );
    vGrey2->setMargin( 5, 5, 5, 5 );
    vGrey2->setPadding( 5, 5, 5, 5 );
    vGrey2->dragable = true;
    
    GUI_IconView *vGreenXX2 = GUI_IconView::create( vGrey2, kIcon_solid_sun, "fa-regular-400.ttf", 100, 0, 0, -1, -1 );
    vGreenXX2->setBackgroundColor( cGreen );
    vGreenXX2->dragable = true;
    vGreenXX2->setAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_CENTER );
    vGreenXX2->setContentAlign( GUI_ALIGN_VCENTER | GUI_ALIGN_CENTER );
    vGreenXX2->setMargin( 5, 5, 5, 5 );
    vGreenXX2->setPadding( 5, 5, 5, 5 );
    

    GUI_Run();
    GUI_Destroy();

    /* shutdown SDL */
    SDL_Quit();

    return 0;
}




