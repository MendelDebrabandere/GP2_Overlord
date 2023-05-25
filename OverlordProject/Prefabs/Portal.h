#pragma once
class PostPortalMaterial;
class PortalMaterial;
class Character;

enum class PortalType
{
	Orange = 0,
	Blue = 1
};


class Portal final : public GameObject
{
public:
	Portal(PortalType type, Portal* pLinkedPortal);
	~Portal() override = default;

	Portal(const Portal& other) = delete;
	Portal(Portal&& other) noexcept = delete;
	Portal& operator=(const Portal& other) = delete;
	Portal& operator=(Portal&& other) noexcept = delete;

	void SetLinkedPortal(Portal* pPortal) { m_pLinkedPortal = pPortal; }

	PortalMaterial* GetScreenMat() const { return m_pScreenMat; }
	FreeCamera* GetCamera() const { return m_pCameraObject; }
	RenderTarget* GetRenderTarget() const { return m_pRenderTarget; }

	void Initialize(const SceneContext&) override;
	void Update(const SceneContext&) override;

	void SetNearClipPlane();

	float GetPortalDir() const { return m_PortalDir; }
private:
	Portal* m_pLinkedPortal{};

	FreeCamera* m_pCameraObject{};
	CameraComponent* m_pCameraComponent{};

	RenderTarget* m_pRenderTarget{};

	ModelComponent* m_pPortalModel{};
	PortalMaterial* m_pScreenMat{};
	PortalType m_Type{};

	XMFLOAT4 m_Color{};

	float m_PortalDir{};

};

