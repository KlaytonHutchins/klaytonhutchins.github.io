---
layout: default
title: Common Docker Commands
---

### Quick Reference

This page provides a quick reference of commonly used Docker commands organized by category.

### Container Management

#### Running Containers

```bash
# Run container
docker run [OPTIONS] IMAGE [COMMAND]

# Common options
docker run -d                    # Detached mode
docker run -it                   # Interactive with terminal
docker run --rm                  # Remove after exit
docker run --name my-container   # Name container
docker run -p 8080:80            # Port mapping
docker run -v /host:/container   # Volume mount
docker run -e VAR=value          # Environment variable
docker run --network my-net      # Specify network

# Examples
docker run -d -p 80:80 --name web nginx
docker run -it --rm ubuntu bash
docker run -d -e POSTGRES_PASSWORD=secret postgres
```

#### Container Lifecycle

```bash
# List containers
docker ps                # Running containers
docker ps -a             # All containers
docker ps -q             # Only container IDs
docker ps -l             # Latest container

# Start/Stop
docker start CONTAINER
docker stop CONTAINER
docker restart CONTAINER
docker pause CONTAINER
docker unpause CONTAINER
docker kill CONTAINER    # Force stop

# Remove containers
docker rm CONTAINER
docker rm -f CONTAINER   # Force remove running container
docker container prune   # Remove all stopped containers
```

#### Container Information

```bash
# View logs
docker logs CONTAINER
docker logs -f CONTAINER           # Follow logs
docker logs --tail 100 CONTAINER   # Last 100 lines
docker logs -t CONTAINER           # With timestamps

# Inspect container
docker inspect CONTAINER
docker inspect -f '{{.State.Status}}' CONTAINER

# View processes
docker top CONTAINER

# Resource usage
docker stats                # All containers
docker stats CONTAINER      # Specific container
```

#### Executing Commands

```bash
# Execute command in running container
docker exec CONTAINER COMMAND

# Interactive shell
docker exec -it CONTAINER bash
docker exec -it CONTAINER sh

# As specific user
docker exec -u root CONTAINER command

# Examples
docker exec web ls /etc
docker exec -it db psql -U postgres
docker exec web cat /var/log/nginx/access.log
```

#### Copying Files

```bash
# Copy from container to host
docker cp CONTAINER:/path/file.txt ./file.txt

# Copy from host to container
docker cp ./file.txt CONTAINER:/path/file.txt

# Copy directory
docker cp CONTAINER:/app ./app-backup
```

### Image Management

#### Working with Images

```bash
# List images
docker images
docker images -a         # Include intermediate images
docker images -q         # Only image IDs

# Pull image
docker pull IMAGE
docker pull IMAGE:TAG
docker pull nginx:1.21

# Push image
docker push IMAGE:TAG

# Search images
docker search nginx
docker search --limit 5 nginx

# Remove images
docker rmi IMAGE
docker rmi -f IMAGE      # Force remove
docker image prune       # Remove unused images
docker image prune -a    # Remove all unused images
```

#### Building Images

```bash
# Build from Dockerfile
docker build -t IMAGE:TAG .
docker build -t IMAGE:TAG -f Dockerfile.prod .
docker build --no-cache -t IMAGE:TAG .
docker build --build-arg VAR=value -t IMAGE:TAG .

# Tag image
docker tag SOURCE:TAG TARGET:TAG
docker tag my-app:latest my-app:v1.0

# View build history
docker history IMAGE

# Save/Load images
docker save -o image.tar IMAGE
docker load -i image.tar

# Export/Import container
docker export CONTAINER > container.tar
docker import container.tar IMAGE:TAG
```

### Volume Management

```bash
# Create volume
docker volume create VOLUME

# List volumes
docker volume ls
docker volume ls -q      # Only volume names

# Inspect volume
docker volume inspect VOLUME

# Remove volume
docker volume rm VOLUME
docker volume prune      # Remove unused volumes

# Use volume
docker run -v VOLUME:/path IMAGE
```

### Network Management

```bash
# Create network
docker network create NETWORK
docker network create --driver bridge NETWORK

# List networks
docker network ls

# Inspect network
docker network inspect NETWORK

# Connect/Disconnect container
docker network connect NETWORK CONTAINER
docker network disconnect NETWORK CONTAINER

# Remove network
docker network rm NETWORK
docker network prune     # Remove unused networks
```

### Docker Compose

```bash
# Start services
docker-compose up
docker-compose up -d             # Detached mode
docker-compose up --build        # Build before starting
docker-compose up --force-recreate

# Stop services
docker-compose stop
docker-compose down              # Stop and remove
docker-compose down -v           # Also remove volumes

# View services
docker-compose ps
docker-compose logs
docker-compose logs -f SERVICE
docker-compose logs --tail=100

# Execute commands
docker-compose exec SERVICE COMMAND
docker-compose exec web bash
docker-compose run SERVICE COMMAND

# Build
docker-compose build
docker-compose build --no-cache SERVICE

# Scale services
docker-compose up -d --scale SERVICE=3

# Other
docker-compose config            # Validate config
docker-compose pull              # Pull images
docker-compose restart
docker-compose pause
docker-compose unpause
```

### System Management

```bash
# View Docker info
docker info
docker version

# Disk usage
docker system df
docker system df -v

# Clean up
docker system prune              # Remove unused data
docker system prune -a           # Remove all unused data
docker system prune --volumes    # Include volumes

# Events
docker events
docker events --filter type=container
```

### Registry and Hub

```bash
# Login to registry
docker login
docker login registry.example.com
docker logout

# Tag for registry
docker tag IMAGE:TAG registry.example.com/IMAGE:TAG

# Push to registry
docker push registry.example.com/IMAGE:TAG

# Pull from registry
docker pull registry.example.com/IMAGE:TAG
```

### Useful Command Patterns

#### Development Workflow

```bash
# Start fresh development environment
docker-compose down -v && docker-compose up --build

# View logs while developing
docker-compose logs -f api

# Run tests
docker-compose exec api npm test

# Access database
docker-compose exec db psql -U postgres

# Rebuild and restart single service
docker-compose up -d --build api
```

#### Debugging

```bash
# View logs
docker logs -f --tail 100 CONTAINER

# Open shell in container
docker exec -it CONTAINER sh

# View processes
docker top CONTAINER

# View resource usage
docker stats CONTAINER

# Inspect container details
docker inspect CONTAINER

# Test network connectivity
docker exec CONTAINER ping other-container
docker exec CONTAINER curl http://api:3000
```

#### Cleanup

```bash
# Remove stopped containers
docker container prune

# Remove unused images
docker image prune -a

# Remove unused volumes
docker volume prune

# Remove unused networks
docker network prune

# Remove everything unused
docker system prune -a --volumes

# Remove specific things
docker rm $(docker ps -aq)           # All containers
docker rmi $(docker images -q)       # All images
```

#### Production Deployment

```bash
# Pull latest images
docker-compose pull

# Update and restart services
docker-compose up -d

# View running services
docker-compose ps

# View logs
docker-compose logs -f --tail=100

# Backup volume
docker run --rm -v DATA:/data -v $(pwd):/backup alpine tar czf /backup/backup.tar.gz /data

# Rollback to previous image
docker tag my-app:latest my-app:previous
docker pull my-app:v1.0
docker tag my-app:v1.0 my-app:latest
docker-compose up -d
```

### Command Options Quick Reference

#### docker run Options

| Option | Description |
|--------|-------------|
| `-d` | Detached mode |
| `-it` | Interactive with terminal |
| `--rm` | Remove after exit |
| `--name` | Container name |
| `-p HOST:CONTAINER` | Port mapping |
| `-v HOST:CONTAINER` | Volume mount |
| `-e VAR=value` | Environment variable |
| `--network` | Network to connect to |
| `--restart` | Restart policy |
| `-w` | Working directory |
| `-u` | User to run as |
| `--cpus` | CPU limit |
| `--memory` | Memory limit |

#### docker logs Options

| Option | Description |
|--------|-------------|
| `-f` | Follow log output |
| `--tail N` | Show last N lines |
| `-t` | Show timestamps |
| `--since` | Show logs since timestamp |
| `--until` | Show logs until timestamp |

#### docker build Options

| Option | Description |
|--------|-------------|
| `-t NAME:TAG` | Name and tag |
| `-f FILE` | Dockerfile path |
| `--no-cache` | Don't use cache |
| `--build-arg` | Build-time variable |
| `--target` | Build specific stage |

### Shell Aliases (Optional)

Add these to your `.bashrc` or `.zshrc`:

```bash
# Docker
alias d='docker'
alias dc='docker-compose'
alias dps='docker ps'
alias dpsa='docker ps -a'
alias di='docker images'
alias dex='docker exec -it'
alias dlog='docker logs -f'

# Docker Compose
alias dcup='docker-compose up -d'
alias dcdown='docker-compose down'
alias dclog='docker-compose logs -f'
alias dcps='docker-compose ps'

# Cleanup
alias dprune='docker system prune -a --volumes'
alias dclean='docker rm $(docker ps -aq) && docker rmi $(docker images -q)'
```

> ### Skill++
> Docker commands are designed to be predictable - most follow the pattern `docker <object> <action>`, like `docker container rm` or `docker image ls`!

<hr>

[Prev](dockerVolumes.md) -- [Up](README.md)
