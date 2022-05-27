#pragma once
#include <string>
#include <vector>


class Texture
{
private:
	unsigned int m_RenderID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;

public:
    Texture(const std::string& path);
    Texture(const std::vector<std::string> faces);
	~Texture();

	void Bind(unsigned int slot = 0) const;
    void BindCubeMap() const;
    void Unbind() const;
    void UnbindCubeMap() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};
