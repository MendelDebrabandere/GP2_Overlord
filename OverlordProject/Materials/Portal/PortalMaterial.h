#pragma once
class PortalMaterial final : public Material<PortalMaterial>
{
public:
	PortalMaterial();
	~PortalMaterial() override = default;
	PortalMaterial(const PortalMaterial& other) = delete;
	PortalMaterial(PortalMaterial&& other) noexcept = delete;
	PortalMaterial& operator=(const PortalMaterial& other) = delete;
	PortalMaterial& operator=(PortalMaterial&& other) noexcept = delete;

protected:
	void InitializeEffectVariables() override;
};

