##
## EPITECH PROJECT, 2018
## cpp_indie
## File description:
## cpp_indie
##

CCPP		=	g++

RM		=	rm -f

CPPFLAGS	=	-W -Werror -Wall -Wextra
CPPFLAGS	+=	-lIrrlicht -lGL -lX11 -lXxf86vm
CPPFLAGS	+=	-I./object -I./character -I./ -I./../lib/IrrKlang/include -I./animation
CPPFLAGS	+=	-L./../lib/IrrKlang/ -lIrrKlang -pthread

NAME		=	indie

SRCS		=	Main.cpp			\
			Core.cpp			\
			IndieWindow.cpp			\
			IndieRendering.cpp		\
			IndieEventReceiver.cpp		\
			GraphObj.cpp			\
			GraphNb.cpp			\
			Map.cpp				\
			Info3d.cpp			\
			Menu.cpp			\
			UI.cpp				\
			Sound.cpp			\
			object/Block.cpp		\
			object/Bomb.cpp			\
			object/BombUp.cpp		\
			object/FireUp.cpp		\
			object/SpeedUp.cpp		\
			object/WallPass.cpp		\
			character/BasicPlayer.cpp	\
			character/NPC.cpp		\
			character/PC.cpp		\
			animation/AnimFireExplo.cpp

OBJS		=	$(SRCS:.cpp=.o)

$(NAME)		:	$(OBJS)
			$(CCPP) $(OBJS) $(CPPFLAGS) -o $(NAME)

all		:	$(NAME)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
