#include <GameObjects/GameObject.hpp>

namespace Slug
{
	namespace Objects
	{
		class Weapon;

		class Spartan : public GameObject
		{
		private:
			Weapon* m_pWeapon;

		public:
			Spartan();
			Spartan(float posX, float posY);
			Spartan(const Vector2& initPos);
			~Spartan();

			// Inherited via GameObject
			virtual void Update(double deltaSeconds) override;
			virtual void Render(SDL_Renderer* const pRenderer) override;
	
			void Input(const SDL_Event& event);
		};
	}
}