#! /bin/bash
xhost +local:docker
docker run \
  --rm \
  --device /dev/video0 \
  -e DISPLAY=${DISPLAY} \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  --env="QT_X11_NO_MITSHM=1" \
  -it -v $(pwd)/:/tmp/game docker-sdl /bin/bash /tmp/game/run.sh
xhost -local:docker
