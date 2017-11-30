#pragma once

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace Physics 
{
	class Collider;

	class PhysicsObjects
	{
	public:
		PhysicsObjects();
		virtual ~PhysicsObjects();

		void Update(float deltaTime);

		void ApplyForce(const glm::vec3 &force);


		// Getters and Setters
		const glm::vec3 &GetPosition() const					{ return m_position; }
		const glm::vec3 &GetVelocity() const					{ return m_velocity; }
		const glm::vec3 &GetAcceleration() const				{ return m_acceleration; };
		const float GetMass() const							{ return m_mass; }
		const float GetFriction() const						{ return m_friction; }
		Collider* GetCollider();

		void SetPosition(const glm::vec3 &setPos)			{ m_position = setPos; }
		void SetVelocity(const glm::vec3 &setVel)			{ m_velocity = setVel; }
		void SetAcceleration(const glm::vec3 &setAccel)		{ m_acceleration = setAccel; }
		void SetMass(float tempMass)						{ m_mass = tempMass; }
		void SetFriction(float tempFric)					{m_friction = tempFric; }
		void SetCollider(Collider*collider);

	protected:
		glm::vec3 m_position = glm::vec3(0, 0, 0);
		glm::vec3 m_velocity = glm::vec3(0, 0, 0);
		glm::vec3 m_acceleration = glm::vec3(0, 0, 0);
		float m_mass = 1.0f;
		float m_friction = 1.0f;

		Collider* m_collider = nullptr;
	private:

	};
}




