#include "PhysicsRenderer.h"
#include "PhysicsScene.h"
#include "PhysicsObjects.h"
#include "Collider.h"
#include "SphereCollider.h"

#include <vector>

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#include <Gizmos.h>

Physics::PhysicsRenderer::PhysicsRenderer()
{
}

Physics::PhysicsRenderer::~PhysicsRenderer()
{
}

void Physics::PhysicsRenderer::Draw(PhysicsScene * scene)
{
	RenderGizmosPhysics(scene);

	
}

void Physics::PhysicsRenderer::RenderGizmosPhysics(PhysicsScene * scene)
{
	const std::vector<Physics::PhysicsObjects*> objects = scene->GetObjects();
	for (auto iter = objects.begin(); iter != objects.end(); iter++)
	{
		Physics::PhysicsObjects *obj = *iter;
		RenderInfo *info = GetRenderInfo(obj);

		glm::vec4 renderColor = info->color;

		if (scene->isObjectColliding(obj))
		{
			renderColor = glm::vec4(1, 0, 0, 1);
		}

		switch (obj->GetCollider()->GetType())
		{
		case Collider::Type::SPHERE: // Draw a collider to the actual size of the sphere
			aie::Gizmos::addSphere(obj->GetPosition(),((SphereCollider*)obj->GetCollider())->GetRadius(), 10, 10, renderColor);
		case Collider::Type::NONE: // No collider, just show a small sphere
			aie::Gizmos::addSphere(obj->GetPosition(), 0.2f, 10, 10, renderColor);
		default:
			break;
		}
		
	}
}
