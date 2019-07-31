#pragma once
#include <GameObjects/GameObject.hpp>
#include "Utils/tinyxml2.h"
#include <unordered_map>
#include <vector>

using tinyxml2::XMLDocument;
using tinyxml2::XMLElement;

namespace Slug
{
	namespace Objects
	{
		class Character : public GameObject
		{
		// --- Member Variables ---
		protected:
			/* ---------- Animation Related -------------*/	
			enum class AnimationType
			{
				kIdle,
				kWalk,
				kAttack,
				kDie
			};

			struct Frame
			{
				SDL_Rect m_sourcePosition;
			};

			struct Animation
			{
				std::vector<Frame> m_frames;
				//Vector2 m_center;
				float m_animationSpeed;
				float m_frameDuration;
				bool m_shouldLoop;
			};
			/* ------------------------------------------*/

			XMLDocument		m_doc;
			XMLElement*		m_pRoot;
			AnimationType	m_animType;
			const char*		m_pSpritePath;

			std::unordered_map<AnimationType, Animation> m_animMap;
			AnimationType m_currentAnim;

			float m_frameTimer;
			int m_currentFrameIndex;


		// --- Member Functions ---
		protected:
		public:
			virtual ~Character() = 0 {};

			// Inherited via GameObject
			virtual void Initialize() = 0;
			virtual void Update(double deltaSeconds) = 0;
			virtual void Render(SDL_Renderer* const pRenderer) = 0;
			virtual void SetTexture(const char* pSpritePath) = 0;

			virtual void InitAnimation() = 0;
			virtual void SetAnimation(int type) = 0;
		};
	}
}
