import subprocess

def build_custom_addon():
    try:
        # Step 1: Cross-compile the add-on for the amd64 architecture
        print("Cross-compiling the add-on for the amd64 architecture...")
        subprocess.run(["docker", "run", "--rm", "--privileged", "-v", "$(pwd):/data", "homeassistant/amd64-builder", "--amd64", "-t", "/data", "--no-cache"], check=True)
        print("Cross-compilation completed successfully.")

        # Step 2: Build the Docker image for the custom add-on
        print("Building the Docker image for the custom add-on...")
        subprocess.run(["docker", "build", "--build-arg", "BUILD_FROM=homeassistant/amd64-base:latest", "-t", "local/my-test-addon", "."], check=True)
        print("Docker image build completed successfully.")

        return "Build process completed successfully."

    except subprocess.CalledProcessError as e:
        return f"Build process failed with error: {str(e)}"

print(build_custom_addon())