﻿#include <app/s3App.h>
#include <app/s3Renderer.h>
#include <app/s3Window.h>
#include <app/s3CallbackManager.h>
#include <core/s3Settings.h>

// testing
#include <core/log/s3Log.h>

LRESULT windowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    case WM_CLOSE:
    {
        DestroyWindow(hwnd);
        return 0;
    }

    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }

    case WM_SIZE:
    {
        s3Renderer::get().resize((int) LOWORD(lParam), (int) HIWORD(lParam));
        return 0;
    }
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

s3App::s3App()
{
    window = nullptr;
}

s3App::~s3App()
{
    S3_SAFE_DELETE(window);
}

bool s3App::init()
{
    s3CallbackInit();

    window = new s3Window("Sophia", windowProc, t3Vector2f(1280, 720), t3Vector2f(100, 100));
    if(!window)	
        return false;

    // Window correlation
    RECT clientArea;
    GetClientRect(window->getHandle(), &clientArea);
    int width = clientArea.right - clientArea.left;
    int height = clientArea.bottom - clientArea.top;

    if(!s3Renderer::get().init(window->getHandle(), width, height))	return false;

    return true;
}

void s3App::shutdown()
{
    S3_SAFE_DELETE(window);
    s3Renderer::get().shutdown();

    s3CallbackDeinit();
}

void s3App::render()
{
    s3CallbackManager::callBack.onUpdate.trigger();

    s3Renderer::get().clear(t3Vector4f(.75f, .75f, .75f, 1.0f));

    s3CallbackManager::callBack.onBeginRender.trigger();
    s3CallbackManager::callBack.onEndRender.trigger();

    s3Renderer::get().present(0, 0);
}

void s3App::run()
{
    MSG msg;
    while(true)
    {
        while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if(msg.message == WM_QUIT)
            {
                shutdown();
                return;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        render();
    }
}

s3Window * s3App::getWindow()
{
    return window;
}
