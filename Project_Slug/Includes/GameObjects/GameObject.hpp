#pragma once
#include <SDL.h>
#include "Utils/Transform.hpp"

namespace Slug
{
	namespace Utils
	{
		class Transform;
	}

	namespace Objects
	{
		class GameObject
		{
		// --- Member Variables ---
		protected:
			Movement		m_moveDir;
			SDL_Rect		m_destRect;
			SDL_Rect		m_resourceRect;
			SDL_Texture*	m_pTexture;
			SDL_Point		m_center;
			Utils::Transform m_transform;

		// --- Member Functions ---
		private:
		public:
			virtual ~GameObject() = 0{};

			virtual void Initialize() = 0;
			virtual void Update(double deltaSeconds) = 0;
			virtual void Render(SDL_Renderer* const pRenderer) = 0;
			void SetTexture(const char* pSpritePath);

			SDL_Rect GetDestRect() { return m_destRect; }
			SDL_Rect GetResourceRect() { return m_resourceRect; }
			SDL_Point GetCenter() { return m_center; }
			inline Utils::Transform& GetTransform() { return m_transform; }
			
			inline Movement GetMovement() { return m_moveDir; }
			inline Movement* GetMovementPtr()
			{
				Movement* pMove = &m_moveDir;
				return pMove;
			}
		};
	}
}

