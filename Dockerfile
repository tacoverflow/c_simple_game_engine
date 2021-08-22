FROM debian
RUN apt update -y
RUN apt install -y build-essential
RUN apt install -y libsdl2-dev
RUN apt install -y libsdl2-image-dev 
