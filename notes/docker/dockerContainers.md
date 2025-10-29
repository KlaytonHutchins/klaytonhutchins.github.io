---
layout: default
title: Docker Containers
---

### What are Containers?

A container is a runnable instance of an image. You can:
* Create, start, stop, move, or delete containers
* Connect containers to networks
* Attach storage to containers
* Create new images based on container state

Multiple containers can run from the same image simultaneously, each isolated from the others.

### Container Lifecycle

```
Created → Running → Paused → Stopped → Removed
```

### Running Containers

#### Basic Run Command

```bash
# Run a container from an image
docker run nginx

# Run in detached mode (background)
docker run -d nginx

# Run with a custom name
docker run --name my-nginx nginx

# Run and remove after exit
docker run --rm nginx
```

#### Interactive Containers

```bash
# Run with interactive terminal
docker run -it ubuntu bash

# Run and execute a command
docker run ubuntu echo "Hello Docker"
```

**Flags:**
* `-i` - Interactive mode (keep STDIN open)
* `-t` - Allocate a pseudo-TTY (terminal)

#### Port Mapping

```bash
# Map container port to host port
docker run -p 8080:80 nginx

# Map to random host port
docker run -P nginx

# Map multiple ports
docker run -p 8080:80 -p 8443:443 nginx
```

Format: `-p host_port:container_port`

#### Environment Variables

```bash
# Set environment variable
docker run -e MY_VAR=value nginx

# Multiple variables
docker run -e VAR1=value1 -e VAR2=value2 nginx

# Load from file
docker run --env-file .env nginx
```

### Managing Containers

#### Listing Containers

```bash
# List running containers
docker ps

# List all containers (including stopped)
docker ps -a

# Show only container IDs
docker ps -q

# Show latest created container
docker ps -l
```

#### Starting and Stopping

```bash
# Start a stopped container
docker start my-container

# Stop a running container (graceful)
docker stop my-container

# Kill a container (force stop)
docker kill my-container

# Restart a container
docker restart my-container

# Pause a running container
docker pause my-container

# Unpause a paused container
docker unpause my-container
```

#### Removing Containers

```bash
# Remove a stopped container
docker rm my-container

# Force remove a running container
docker rm -f my-container

# Remove all stopped containers
docker container prune

# Remove container after it exits
docker run --rm nginx
```

### Executing Commands in Containers

```bash
# Execute command in running container
docker exec my-container ls /app

# Open interactive shell in running container
docker exec -it my-container bash

# Execute as different user
docker exec -u root my-container whoami
```

### Viewing Container Information

#### Logs

```bash
# View container logs
docker logs my-container

# Follow log output (like tail -f)
docker logs -f my-container

# Show last 100 lines
docker logs --tail 100 my-container

# Show logs with timestamps
docker logs -t my-container
```

#### Inspect

```bash
# View detailed container information
docker inspect my-container

# Get specific field (using Go template)
docker inspect -f '{{.State.Status}}' my-container

# View network settings
docker inspect -f '{{.NetworkSettings.IPAddress}}' my-container
```

#### Stats

```bash
# View resource usage statistics
docker stats

# Stats for specific container
docker stats my-container

# Show stats once (no streaming)
docker stats --no-stream
```

#### Top

```bash
# View processes running in container
docker top my-container
```

### Copying Files

```bash
# Copy from container to host
docker cp my-container:/app/file.txt ./file.txt

# Copy from host to container
docker cp ./file.txt my-container:/app/file.txt

# Copy entire directory
docker cp my-container:/app ./app-backup
```

### Container Resource Limits

```bash
# Limit CPU usage
docker run --cpus=".5" nginx

# Limit memory
docker run --memory="512m" nginx

# Limit both
docker run --cpus=".5" --memory="512m" nginx
```

### Common Patterns

#### Running a Web Server

```bash
# Run nginx on port 8080
docker run -d -p 8080:80 --name web-server nginx
```

#### Running a Database

```bash
# Run MySQL with environment variables
docker run -d \
  --name mysql-db \
  -e MYSQL_ROOT_PASSWORD=secret \
  -e MYSQL_DATABASE=myapp \
  -p 3306:3306 \
  mysql:8.0
```

#### Debugging a Container

```bash
# View logs
docker logs -f my-container

# Open shell
docker exec -it my-container bash

# View processes
docker top my-container

# View resource usage
docker stats my-container
```

> ### Skill++
> A single Docker host can run hundreds or even thousands of containers simultaneously, limited primarily by available memory and CPU.

<hr>

[Prev](dockerImages.md) -- [Up](README.md) -- [Next](dockerfiles.md)
