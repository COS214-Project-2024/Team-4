files = main.o Airport.o Bus.o CargoAirport.o ComercialAirport.o FreightTrain.o Highway.o InsideRoad.o LunchRush.o NonPeak.o PassengerTrain.o Peak.o PublicTransit.o  Road.o Taxi.o TrafficFlow.o Train.o Transportation.o TransportationFactory.o TransportManager.o
gpp = g++ -c -g

main: $(files)
	g++ -o main $(files)

TrafficFlow.o: TrafficFlow.cpp TrafficFlow.h
	$(gpp) TrafficFlow.cpp

Peak.o: Peak.cpp Peak.h TrafficFlow.h
	$(gpp) Peak.cpp

LunchRush.o: LunchRush.cpp LunchRush.h TrafficFlow.h
	$(gpp) LunchRush.cpp

NonPeak.o: NonPeak.cpp NonPeak.h TrafficFlow.h
	$(gpp) NonPeak.cpp

Transportation.o: Transportation.cpp Transportation.h TrafficFlow.h Peak.h LunchRush.h NonPeak.h	
	$(gpp) Transportation.cpp

Airport.o: Airport.cpp Airport.h Transportation.h
	$(gpp) Airport.cpp

PublicTransit.o: PublicTransit.cpp PublicTransit.h Transportation.h
	$(gpp) PublicTransit.cpp

Road.o: Road.cpp Road.h Transportation.h
	$(gpp) Road.cpp

Train.o: Train.cpp Train.h Transportation.h
	$(gpp) Train.cpp

Bus.o: Bus.cpp Bus.h PublicTransit.h InsideRoad.h ComercialAirport.h PassengerTrain.h
	$(gpp) Bus.cpp

CargoAirport.o: CargoAirport.cpp CargoAirport.h Airport.h InsideRoad.h
	$(gpp) CargoAirport.cpp

ComercialAirport.o: ComercialAirport.cpp ComercialAirport.h Airport.h InsideRoad.h
	$(gpp) ComercialAirport.cpp

FreightTrain.o: FreightTrain.cpp FreightTrain.h Train.h InsideRoad.h
	$(gpp) FreightTrain.cpp

Highway.o: Highway.cpp Highway.h Road.h InsideRoad.h
	$(gpp) Highway.cpp

InsideRoad.o: InsideRoad.cpp InsideRoad.h Road.h Highway.h Bus.h Taxi.h ComercialAirport.h CargoAirport.h PassengerTrain.h FreightTrain.h
	$(gpp) InsideRoad.cpp

PassengerTrain.o: PassengerTrain.cpp PassengerTrain.h Train.h InsideRoad.h
	$(gpp) PassengerTrain.cpp

Taxi.o: Taxi.cpp Taxi.h PublicTransit.h InsideRoad.h ComercialAirport.h CargoAirport.h PassengerTrain.h FreightTrain.h	
	$(gpp) Taxi.cpp

TransportationFactory.o: TransportationFactory.cpp TransportationFactory.h Transportation.h InsideRoad.h Highway.h Bus.h Taxi.h ComercialAirport.h CargoAirport.h PassengerTrain.h FreightTrain.h
	$(gpp) TransportationFactory.cpp

TransportManager.o: TransportManager.cpp TransportManager.h Transportation.h TransportationFactory.h
	$(gpp) TransportManager.cpp

main.o: main.cpp TransportManager.h
	$(gpp) main.cpp

run: main
	./main

clean:
	rm -f *.o main

valgrind: main
	valgrind --leak-check=full ./main

gdb: main
	gdb ./main