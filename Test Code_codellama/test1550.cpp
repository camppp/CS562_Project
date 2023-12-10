#pragma once

#include "TestBase/Application.hpp"
#include "TestBase/DefaultProcessingPipeline.hpp"
#include "Object.hpp"

namespace Flint
{
	class Sponza : public Object
	{
	public:
		Sponza() = default;
		~Sponza() = default;

		void loadModel(const std::string& filePath)
		{
			// Load the 3D model from the specified file
			// ...

			// Store the file path in the modelFilePath variable
			modelFilePath = filePath;
		}

		void render()
		{
			// Render the loaded 3D model to the screen
			// ...
		}

	private:
		std::string modelFilePath;
	};
}
