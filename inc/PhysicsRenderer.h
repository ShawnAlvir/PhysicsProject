#pragma once

#include <glm/vec4.hpp>

#include <map>

namespace Physics 
{
	class PhysicsScene;
	class PhysicsObjects;

	class PhysicsRenderer
	{
	public:
		struct RenderInfo
		{
			glm::vec4 color = glm::vec4(1, 1, 1, 1);
		};


		PhysicsRenderer();
		virtual ~PhysicsRenderer();

		virtual void Draw(PhysicsScene * scene);

		PhysicsRenderer::RenderInfo* GetRenderInfo(PhysicsObjects *obj) { return &m_renderInfo[obj]; }

	protected:
		std::map<PhysicsObjects*, RenderInfo> m_renderInfo;

	private:
		void RenderGizmosPhysics(PhysicsScene * scene);
		
	};
}



