#include "PhysicsObjects.h"
#include "Collider.h"

#include <glm/vec3.hpp>

//=========================================================================
//=========================================================================
using namespace Physics;

PhysicsObjects::PhysicsObjects()
{
}

PhysicsObjects::~PhysicsObjects()
{
	delete m_collider;
}

// Force = mass * acceleration
// Acceleration = force / mass

// Acceleration changes velocity over time
// Velocity changes position over time

void PhysicsObjects::Update(float deltaTime)
{
	ApplyForce(-m_velocity * m_friction);
	m_velocity += m_acceleration * deltaTime;
	m_position += m_velocity * deltaTime;
	m_acceleration = glm::vec3();

	m_collider->Transform(this);

}

void PhysicsObjects::ApplyForce(const glm::vec3 & force)
{
	m_acceleration += force / m_mass;
}

Collider * PhysicsObjects::GetCollider()
{
	if (m_collider == nullptr)
	{
		return Collider::GetNullInstance();
	}
	return m_collider;
}

void PhysicsObjects::SetCollider(Collider * collider)
{
	// Clear memory for the old collider we owned
	delete m_collider;

	// Take ownership of a new collider
	m_collider = collider;
	m_collider->Transform(this);

}


