//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include "DebugCamera.h"
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>
#include <Keyboard.h>

const int MAX_BALL = 20;


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_Batch;
	std::unique_ptr<DirectX::BasicEffect> m_Effect;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;
	
	DirectX::SimpleMath::Matrix m_world;
	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;
	DirectX::SimpleMath::Matrix m_transmat[MAX_BALL];

	int cnt;

	float tank_angle;

	//エフェクト
	std::unique_ptr<DirectX::EffectFactory> m_factory;

	//地面
	std::unique_ptr<DirectX::Model>m_Ground;
	//空
	std::unique_ptr<DirectX::Model>m_Skydome;
	//球
	std::unique_ptr<DirectX::Model>m_ball;
	//ティーカップ
	std::unique_ptr<DirectX::Model>m_Tea;
	//タンク
	std::unique_ptr<DirectX::Model>m_Tank;

	//球のワールド行列
	DirectX::SimpleMath::Matrix m_worldBall[MAX_BALL];
	//
	DirectX::SimpleMath::Matrix m_worldTea[MAX_BALL];

	//デバッグカメラ
	std::unique_ptr<DebugCamera> m_debugCamera;
	//キーボード
	std::unique_ptr<DirectX::Keyboard>m_keyboard;
	//自機の座標
	DirectX::SimpleMath::Vector3 tank_pos;
	//自機のワールド行列
	DirectX::SimpleMath::Matrix m_worldTank;

	DirectX::SimpleMath::Matrix m_rotmatz;

	DirectX::SimpleMath::Matrix m_rotmatx;

	DirectX::SimpleMath::Matrix m_rotmaty;

	DirectX::SimpleMath::Matrix m_rotmat;
};