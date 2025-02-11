#pragma once

struct CharacterDesc
{
	CharacterDesc(
		PxMaterial* pMaterial,
		float radius = .5f,
		float height = 2.f)
	{
		controller.setToDefault();
		controller.radius = radius;
		controller.height = height;
		controller.material = pMaterial;
	}

	float maxMoveSpeed{ 15.f };
	float maxFallSpeed{ 15.f };

	float JumpSpeed{ 15.f };

	float moveAccelerationTime{ .3f };
	float fallAccelerationTime{ .3f };

	PxCapsuleControllerDesc controller{};

	float rotationSpeed{ 60.f };

	int actionId_MoveLeft{ -1 };
	int actionId_MoveRight{ -1 };
	int actionId_MoveForward{ -1 };
	int actionId_MoveBackward{ -1 };
	int actionId_Jump{ -1 };
};

class Character : public GameObject
{
public:
	Character(const CharacterDesc& characterDesc);
	~Character() override = default;

	Character(const Character& other) = delete;
	Character(Character&& other) noexcept = delete;
	Character& operator=(const Character& other) = delete;
	Character& operator=(Character&& other) noexcept = delete;

	void DrawImGui();
	void SetCameraActive(bool newValue = true);

	void SetCollisionGroup(CollisionGroup group);
	void SetCollisionIgnoreGroup(CollisionGroup group);

	FixedCamera* GetCamera() { return m_pCameraObject; }
	const CameraComponent* GetCameraComponent() const { return m_pCameraComponent; }

	float GetTpCooldown() const { return m_TpCooldown; }
	void SetTpCooldown(float val);
	void AddCameraRotation(float yaw, float pitch);

	XMFLOAT3 GetVelocity() const { return m_TotalVelocity; }
	void SetVelocity(const XMFLOAT3& v);

	GameObject* GetCube() const { return m_pHoldingCube; }
protected:
	void Initialize(const SceneContext&) override;
	void Update(const SceneContext&) override;

private:
	float m_TpCooldown{};

	FixedCamera* m_pCameraObject{};
	CameraComponent* m_pCameraComponent{};
	ControllerComponent* m_pControllerComponent{};

	CharacterDesc m_CharacterDesc;
	float m_TotalPitch{}, m_TotalYaw{};				//Total camera Pitch(X) and Yaw(Y) rotation
	float m_MoveAcceleration{},						//Acceleration required to reach maxMoveVelocity after 1 second (maxMoveVelocity / moveAccelerationTime)
		m_FallAcceleration{},						//Acceleration required to reach maxFallVelocity after 1 second (maxFallVelocity / fallAccelerationTime)
		m_MoveSpeed{};								//MoveSpeed > Horizontal Velocity = MoveDirection * MoveVelocity (= TotalVelocity.xz)

	XMFLOAT3 m_TotalVelocity{};						//TotalVelocity with X/Z for Horizontal Movement AND Y for Vertical Movement (fall/jump)
	XMFLOAT3 m_CurrentDirection{};					//Current/Last Direction based on Camera forward/right (Stored for deacceleration)

	SpriteFont* m_pFont{};

	GameObject* m_pHoldingCube{};

	ModelAnimator* m_pAnimator{};
	int m_CurrClip{};
	float m_JumpAnimTime{};

	FMOD::Channel* m_pChannelTeleport{ nullptr };
};

