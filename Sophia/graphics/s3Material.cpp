#include <graphics/s3Material.h>

s3Material::s3Material(std::string shaderName)
{

}

s3Material::~s3Material()
{}

float32 s3Material::GetFloat(std::string name) const
{
	return float32();
}

int32 s3Material::GetInt(std::string name) const
{
	return int32();
}

t3Matrix4x4 s3Material::GetMatrix(std::string name) const
{
	return t3Matrix4x4();
}

t3Vector4f s3Material::GetVector(std::string name) const
{
	return t3Vector4f();
}

s3Texture* s3Material::GetTexture(std::string name) const
{
	return nullptr;
}

s3Shader* s3Material::GetShader() const
{
	return nullptr;
}

bool s3Material::IsKeywordEnabled(std::string name) const
{
	return false;
}

bool s3Material::SetKeyword(std::string name, bool enableKeyword)
{
	return false;
}

bool s3Material::SetTexture(std::string name, s3Texture* texture)
{
	return false;
}

bool s3Material::SetInt(std::string name, int32 value)
{
	return false;
}

bool s3Material::SetFloat(std::string name, float32 value)
{
	return false;
}

bool s3Material::SetMatrix(std::string name, t3Matrix4x4 value)
{
	return false;
}

bool s3Material::SetVector(std::string name, t3Vector3f value)
{
	return false;
}
