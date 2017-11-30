#include "PhysicsScene.h"
#include "PhysicsObjects.h"

#include "Collider.h"

#include <algorithm>

using namespace Physics;

PhysicsScene::PhysicsScene()
{
}

PhysicsScene::~PhysicsScene()
{
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++) 
	{
		delete *iter;
	}
	m_objects.clear();
}

void PhysicsScene::Update(float deltaTime)
{
	for (auto iter = m_objects.begin(); iter != m_objects.end(); iter++)
	{
		PhysicsObjects *obj = *iter;
		obj->ApplyForce(m_globalForce);
		obj->Update(deltaTime);

		// Super dodgy gound collision bouncing
		// This will be repkaced be proper collision detection and reaction later
		//----------------------------------------------------------------------------
		const glm::vec3 &pos = obj->GetPosition();
		const glm::vec3 &vel = obj->GetVelocity();

		if (pos.y <0.0f)
		{
			obj->SetPosition(glm::vec3(pos.x, 0.0f, pos.z));
			obj->SetVelocity(glm::vec3(vel.x, -vel.y, vel.z));		}

		//----------------------------------------------------------------------------

		
	}
	m_globalForce = glm::vec3();


	DetectCollisions();
}

void PhysicsScene::ApplyGlobalForce(const glm::vec3 & force)
{
	m_globalForce = force;

}

void PhysicsScene::AttachObjects(PhysicsObjects * obj)
{
	auto iter = std::find(m_objects.begin(), m_objects.end(), obj);
	if (iter == m_objects.end())
	{
		m_objects.push_back(obj);
	}
	
}

void PhysicsScene::RemoveObjects(PhysicsObjects * obj)
{
	auto iter = std::find(m_objects.begin(), m_objects.end(), obj);
	if (iter != m_objects.end()) // object pointer in in our vector
	{
		delete *iter; // Maybe this is needed, but maybe we just "give" the object back to another class
		m_objects.erase(iter);
	}
}

bool Physics::PhysicsScene::isObjectColliding(PhysicsObjects * obj)
{

	//TODO: Make it more efficent (use a map(hashtable))
	for (auto iter = m_collisions.begin(); iter != m_collisions.end(); iter++)
	{
		if ((*iter).objA == obj || (*iter).objB == obj)
		{
			return true;
		}
	}
	return false;
}

void PhysicsScene::DetectCollisions()
{
	m_collisions.clear();// remove old collisions from previous frame

	//TODO: redo for the assessment
	for (auto iterA = m_objects.begin(); iterA != m_objects.end(); iterA++)
	{
		PhysicsObjects* objA = *iterA;
		for (auto iterB = iterA + 1; iterB != m_objects.end(); iterB++)
		{
			PhysicsObjects* objB = *iterB;
				if (objA->GetCollider()->Intersects(objB->GetCollider()))
				{
					CollisionInfo info;
					info.objA = objA;
					info.objB = objB;
					m_collisions.push_back(info);
				}
		}
	}



}
