# Proyecto 1: The clash of the guardians
## Solución del proyecto
#### Para la correcta implementación y creación del programa, se ha implementado un código escrito en lenguaje "C" de programación para el ramo de Algoritmos y estructuras de datos de la Universidad de Talca 
 El trabajo se planteaba de la siguiente manera:
####  ● Existen 60 o más cartas distintas.
####  ● Existen 4 tipos de guardianes; magos,
####  vikingos, nigromantes y bestias.
####  ● Todos los guardianes tienen un nombre
####  que solo es una palabra (sin nombres
####  compuestos).
####  ● Todos los guardianes tienen:
####  ○ Puntos de vida (PV): Representa la
####  salud o la vida.
####  ○ Puntos de Ataque (PA): Representa
####  el daño que puede realizar en combate.
####  ○ Puntos de defensa (PD):
####  Representa la capacidad de reducir el daño
####  recibido.
#### y para ello, este código cuenta con la implementación de la solución al trabajo solicitado, donde se pedía realizar l simulación de una partida del juego señalado anteriormente, de la siguiente manera:

Para empezar, se generaron 3 structs (Guardian, Jugador y Cartas) las cuales almacenaban la información de cada uno. Cada estructura era distinta ya que cada personaje o atriubuto tenía sus propias características que se iban a utilizar a lo largo del código
Luego, se creó un "int main()" donde se llamarán las funciones proximamente creadas para alivianar la sobrecarga de datos dentro del main. Con esto, se crearon distintas funciones debajo del main que serán útiles para distintas funcionalidades del juego. De las cuales eran: (MenuInicial, CargarGuardianes, CrearMazoAleatorio, SeleccionarCartasIniciales, BucleTurnos, MostrarCartas y MostrarMazo) cada una de estas funciones tendrá una funcion específica que en conjunto tomarán un sentido dentro del código. 
Cada funcion es llamada dentro del main en forma de un void, el cual, siguiendo un orden lógico, serán útiles para lograr el proósito propuesto.
Para la creación de un menú principal se creó la funcion MenuInicial, la cual se imprimía en pantalla cada una de las opciones a escoger por el usuario, validando los datos entregados por teclado y que cumpliesen los parámetros dictados por el menú.
Dependiendo del valor entregado por este, era la opción que este podría escoger, entre crear una carta, empezar el juego, mostrar el historial o simplemente salir del juego. Para acceder a cada una se usó un "do-While" el cual funcionaba a modo de bucle que, a su vez validaba la entrada de datos por teclado, tambien daba distintas opciones que, una vez completos, te devolvían al menú principal. 
Al momento de teclear un "2" en el teclado en el menú, este enseguida partía el juego, entregando como primer dato la creación de mazos aleatorios de la función (CrearMazoAleatorio) para el Jugador como para la Computadora (el rival).
Una vez revuelto y creado el mazo aleatorio de 15 cartas para cada uno, este le mostraba por pantalla al jugador las 15 cartas aleatorias de su mazo, de las cuales, mediante teclado, el jugador debiese escoger 3 de ellas, siendo también validados sus parámetros, mediante la función "SeleccionaCartasIniciales" la cual le permitía al usuario poder escoger 3 cartas de ese mazo con una validación de por medio.
Una vez terminado el proceso de seleccion de cartas para el jugador, era turno de la maquina (la computadora) la cual, gracias a la función (SeleccionarCartasAleatorias) la computadora generaba un random que le permitía poder esocger 3 cartas del mazo de 15 cartas hecho previamente al inicio del juego.
Una vez lista la selección de cartas para ambos jugadores, era turno del bucle de juego: Para implementar una buena solución a esta lógica y sistema de juego, se generó un "do-While" el cual repartía los turnos para el jugador y para la computadora. Siendo el jugador el primero en escoger con que carta atacar en batalla, seleccionando un enemigo de forma aleatoria, comparando sus puntos de vida, ataque y defensa. Logrando así un sistema de juego entre comparaciónes de datos.
**Sistema de juego** Para que el bucle de turnos empiece, se creó la variable turno = 1, cartabatalla y cartabatallajugador. Luego, en el "do-While" (para generar el bucle de turnos) se estableció la condición de vidas de cada jugador, mientras ambas vidas sean mayores a 0, el bucle sigue andando. Luego con un if (turno ==1) el juego empezaba su curso normal. Dentro del "do", el jugador debe de seleccionar la carta a mandar a batalla, validando el dato entregado se asignaba un valor de daño como un parámetro entre la diferencia de puntos de ataque y de defensa entre cartas (atacante y defensor respectivamente), entonces era una variable que iba cambiando al pasar el juego. 
Luego si esta variable sobrepasaba los 0 puntos, significaba que había un ataque al jugador directamente, transformándose en -1 punto de vida para el contrincante en cuestión.
Para el turno de la máquina se usó la misma lógica implementada en el jugador, con la leve diferencia que, con la máquina, se necesitaba de usar un valor aleatorio (un random) que permitiese escoger entre 3 cartas con cual atacar y a que carta rival atacar, para ello se generó la semilla de un random en el int main(), y dentro del cópdigo dl bucle del juego se estableció que la variable cartacomputadora = rand%CartasIniciales, función que permitía acceder a las cartas previamente seleccionadas por la computadora, sin perder un orden lógico en el transcurso del código.
De esta forma, el bucle permitía que, tras ataque y defensa de las cartas, uno de los 2 jugadores deberá de llegar a 0 en algun turno, y si así fuese, se imprime un breve texto en pantalla que indica si has ganado tu (jugador) o la computadora (el rival).
[https://drive.google.com/file/d/1-Ai1Oll8KbKfx9cPkGQB86WR1yxJ5--P/view?usp=sharing] Para el link del video.
[https://github.com/Ranafonica/Laboratorios/tree/master] Para el link GitHub del archivo, @Ranafonica



  
