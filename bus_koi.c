#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX_ROUTES 18
#define MAX_STOPS 20
//declearation of 2D array
char routeNames[MAX_ROUTES][50] = {
    "Anabil Super",
    "Thikana Express Limited",
    "RAIDA ENTERPRISE",
    "Alif",
    "Prajapati & Konok",
    "BRTC",
    "BOLAKA",
    "LABBAYEK",  
    "TORONGO PLUS",  
    "BAHON",          
    "NISORGO",        
    "SHOTABDI",       
    "CANTONMENT MINI SERVICE", 
    "RONGDHONU EXPRESS",       
    "BORAK PORIBOHON",          
    "RAJDHANI",                 
    "SUPER BUS",                
    "DHAKA PORIBOHON"
};
//declearation of 3D array
char stops[MAX_ROUTES][MAX_STOPS][50];
int stopCounts[MAX_ROUTES];

void displayMenu();
void initializeRoutes();
void showAllRoutes();
void calculateFare();
void showStopsDetails();
void inputTravelTime();
void inputBusAvailability();
void checkBusAvailability();
void displayEstimatedTravelTime();
void calculateDistance();
void Bus_calculateFare();
void separator();
void collectFeedback();
void displayBusSchedules();
void printTicket();

// Display separator
void separator() {
    printf("---------------------------------------------------\n");
}

// Display Menu
void displayMenu() {
    separator();
    printf("              Welcome to Bus Koi software\n");
    separator();
    printf("1. View All Bus Routes\n");
    printf("2. Select Route & Calculate Fare\n");
    printf("3. View Route Stop Details\n");
    printf("4. Calculate Fare\n");
    printf("5. Input Bus Availability Information\n");
    printf("6. Check Bus Availability\n");
    printf("7. Input Travel Time\n");
    printf("8. Display Estimated Travel Time\n");
    printf("9. Calculate distance\n");
    printf("10. Give Feedback\n");
    printf("11.Print Ticket\n");
    printf("12. Exit\n");
    separator();
}

void initializeRoutes() {
    for (int route = 0; route < 18; route++) {
        switch (route) {
            
            case 0:  // Route 1
                stopCounts[route] = 12;
                strcpy(stops[route][0], "Gazipur Chowrasta");
                strcpy(stops[route][1], "Uttara");
                strcpy(stops[route][2], "Airport");
                strcpy(stops[route][3], "Kuril Flyover");
                strcpy(stops[route][4], "Badda");
                strcpy(stops[route][5], "Khilgaon");
                strcpy(stops[route][6], "Basabo");
                strcpy(stops[route][7], "Titipara");
                strcpy(stops[route][8], "Sayedabad");
                strcpy(stops[route][9], "Jatrabari");
                strcpy(stops[route][10], "Postogola");
                strcpy(stops[route][11], "Signboard");
                break;

            case 1:  // Route 2
                stopCounts[route] = 10;
                strcpy(stops[route][0], "Jirani");
                strcpy(stops[route][1], "EPZ");
                strcpy(stops[route][2], "Nobin Nagar");
                strcpy(stops[route][3], "Savar");
                strcpy(stops[route][4], "Gabtoli");
                strcpy(stops[route][5], "Kolbagan");
                strcpy(stops[route][6], "New Market");
                strcpy(stops[route][7], "Chankharpol");
                strcpy(stops[route][8], "Gulistan");
                strcpy(stops[route][9], "Sayedabad");
                break;

            case 2:  // Route 3
                stopCounts[route] = 11;
                strcpy(stops[route][0], "Diabari Chowrasta");
                strcpy(stops[route][1], "Uttara");
                strcpy(stops[route][2], "Airport");
                strcpy(stops[route][3], "Kuril Flyover");
                strcpy(stops[route][4], "Badda");
                strcpy(stops[route][5], "Khilgaon");
                strcpy(stops[route][6], "Basabo");
                strcpy(stops[route][7], "Titipara");
                strcpy(stops[route][8], "Sayedabad");
                strcpy(stops[route][9], "Jatrabari");
                strcpy(stops[route][10], "Postogola");
                break;

            case 3:  // Route 4
                stopCounts[route] = 9;
                strcpy(stops[route][0], "Mirpur Sony Cinema Hall");
                strcpy(stops[route][1], "Mirpur 10");
                strcpy(stops[route][2], "Kazipara");
                strcpy(stops[route][3], "Shewrapara");
                strcpy(stops[route][4], "Mohakhali");
                strcpy(stops[route][5], "Gulshan 1");
                strcpy(stops[route][6], "Badda");
                strcpy(stops[route][7], "Rampura");
                strcpy(stops[route][8], "Banasree");
                break;

            case 4:  // Route 5
                stopCounts[route] = 8;
                strcpy(stops[route][0], "Gabtoli");
                strcpy(stops[route][1], "Mirpur 1");
                strcpy(stops[route][2], "Mirpur 10");
                strcpy(stops[route][3], "Kalshi");
                strcpy(stops[route][4], "Bisshoroad");
                strcpy(stops[route][5], "Airport");
                strcpy(stops[route][6], "Uttara");
                strcpy(stops[route][7], "Abdullahpur");
                break;

            case 5:  // Route 6
                stopCounts[route] = 9;
                strcpy(stops[route][0], "Balughat");
                strcpy(stops[route][1], "Cantonment");
                strcpy(stops[route][2], "Bijoy Sarani");
                strcpy(stops[route][3], "Farmgate");
                strcpy(stops[route][4], "Banglamotor");
                strcpy(stops[route][5], "Shahbag");
                strcpy(stops[route][6], "Polton");
                strcpy(stops[route][7], "Gulistan");
                strcpy(stops[route][8], "Motijheel");
                break;

            case 6:  // Route 7
                stopCounts[route] = 14;
                strcpy(stops[route][0], "Motijheel");
                strcpy(stops[route][1], "Komlapur");
                strcpy(stops[route][2], "Malibag");
                strcpy(stops[route][3], "Mogbazar");
                strcpy(stops[route][4], "Nabisko");
                strcpy(stops[route][5], "Mohakhali");
                strcpy(stops[route][6], "Banani");
                strcpy(stops[route][7], "Khilkhet");
                strcpy(stops[route][8], "Airport");
                strcpy(stops[route][9], "Uttara");
                strcpy(stops[route][10], "Tongi");
                strcpy(stops[route][11], "Board Bazar");
                strcpy(stops[route][12], "Gazipur");
                strcpy(stops[route][13], "Shib Bari");
                break;

            case 7:  // Route 8
                stopCounts[route] = 12;
                strcpy(stops[route][0], "Jatrabari");
                strcpy(stops[route][1], "Sayedabad");
                strcpy(stops[route][2], "Mugda");
                strcpy(stops[route][3], "Khilgaon");
                strcpy(stops[route][4], "Malibag");
                strcpy(stops[route][5], "Mogbazar");
                strcpy(stops[route][6], "Karwan Bazar");
                strcpy(stops[route][7], "Farmgate");
                strcpy(stops[route][8], "Asadgate");
                strcpy(stops[route][9], "Shyamoli");
                strcpy(stops[route][10], "Gabtoli");
                strcpy(stops[route][11], "Savar");
                break;

            case 8:  // Route 9: TORONGO PLUS
                stopCounts[route] = 10;
                strcpy(stops[route][0], "Mohammadpur Bus Stand");
                strcpy(stops[route][1], "Shankar");
                strcpy(stops[route][2], "Dhanmondi 15");
                strcpy(stops[route][3], "Jhigatola");
                strcpy(stops[route][4], "Science Lab");
                strcpy(stops[route][5], "Shahbag");
                strcpy(stops[route][6], "Kakrail");
                strcpy(stops[route][7], "Malibag Railgate");
                strcpy(stops[route][8], "Rampura Bazar");
                strcpy(stops[route][9], "South Banasree");
                break;

            case 9:  // Route 10: BAHON
                stopCounts[route] = 13;
                strcpy(stops[route][0], "Mirpur 14");
                strcpy(stops[route][1], "Mirpur 10");
                strcpy(stops[route][2], "Mirpur 1");
                strcpy(stops[route][3], "Technical");
                strcpy(stops[route][4], "Kolyanpur");
                strcpy(stops[route][5], "Asadgate");
                strcpy(stops[route][6], "Science Lab");
                strcpy(stops[route][7], "Shahbag");
                strcpy(stops[route][8], "Press Club");
                strcpy(stops[route][9], "Motijheel");
                strcpy(stops[route][10], "Komlapur");
                strcpy(stops[route][11], "Mugda");
                strcpy(stops[route][12], "Khilgaon");
                break;

            case 10:  // Route 11: NISORGO
                stopCounts[route] = 15;
                strcpy(stops[route][0], "Mirpur 14 Bus Stand");
                strcpy(stops[route][1], "Mirpur 10");
                strcpy(stops[route][2], "Kazipara");
                strcpy(stops[route][3], "Agargaon");
                strcpy(stops[route][4], "Shyamoli");
                strcpy(stops[route][5], "Asadgate");
                strcpy(stops[route][6], "Mohammadpur");
                strcpy(stops[route][7], "Dhakmondi 15");
                strcpy(stops[route][8], "Jhigatola");
                strcpy(stops[route][9], "Science Lab");
                strcpy(stops[route][10], "Dhaka College");
                strcpy(stops[route][11], "New Market");
                strcpy(stops[route][12], "Nilkhet");
                strcpy(stops[route][13], "Eden College");
                strcpy(stops[route][14], "Azimpur");
                break;

            case 11:  // Route 12: SHOTABDI
                stopCounts[route] = 14;
                strcpy(stops[route][0], "Mirpur 14 Bus Stand");
                strcpy(stops[route][1], "Mirpur 14");
                strcpy(stops[route][2], "Mirpur 1");
                strcpy(stops[route][3], "Kazipara");
                strcpy(stops[route][4], "Kafrul");
                strcpy(stops[route][5], "Gulshan-1");
                strcpy(stops[route][6], "Farmgate");
                strcpy(stops[route][7], "Gulistan");
                strcpy(stops[route][8], "Mugda");
                strcpy(stops[route][9], "Malibag");
                strcpy(stops[route][10], "Mogbazar");
                strcpy(stops[route][11], "Karwan Bazar");
                strcpy(stops[route][12], "Shahbag");
                strcpy(stops[route][13], "Dhanmondi");
                break;

            case 12:  // Route 13: SAPNA
                stopCounts[route] = 13;
                strcpy(stops[route][0], "Shyamoli");
                strcpy(stops[route][1], "Asadgate");
                strcpy(stops[route][2], "Dhanmondi 15");
                strcpy(stops[route][3], "Science Lab");
                strcpy(stops[route][4], "Jigatola");
                strcpy(stops[route][5], "Motijheel");
                strcpy(stops[route][6], "Komlapur");
                strcpy(stops[route][7], "Rampura");
                strcpy(stops[route][8], "Banasree");
                strcpy(stops[route][9], "Nabisco");
                strcpy(stops[route][10], "Mohakhali");
                strcpy(stops[route][11], "Banani");
                strcpy(stops[route][12], "Mohammadpur");
                break;

            case 13:  // Route 14: MOTOR RIDERS
                stopCounts[route] = 11;
                strcpy(stops[route][0], "Motijheel");
                strcpy(stops[route][1], "Science Lab");
                strcpy(stops[route][2], "Shahbag");
                strcpy(stops[route][3], "Bengali Market");
                strcpy(stops[route][4], "Karwan Bazar");
                strcpy(stops[route][5], "Rampura");
                strcpy(stops[route][6], "Mugda");
                strcpy(stops[route][7], "Mogbazar");
                strcpy(stops[route][8], "Mohakhali");
                strcpy(stops[route][9], "Banani");
                strcpy(stops[route][10], "Savar");
                break;

            case 14:  // Route 15
                stopCounts[route] = 10;
                strcpy(stops[route][0], "Mirpur 10");
                strcpy(stops[route][1], "Kazipara");
                strcpy(stops[route][2], "Kafrul");
                strcpy(stops[route][3], "Gulshan-2");
                strcpy(stops[route][4], "Farmgate");
                strcpy(stops[route][5], "Gulistan");
                strcpy(stops[route][6], "Shahbag");
                strcpy(stops[route][7], "Shankar");
                strcpy(stops[route][8], "Dhanmondi");
                strcpy(stops[route][9], "Shyamoli");
                break;

            case 15:  // Route 16
                stopCounts[route] = 11;
                strcpy(stops[route][0], "Sayedabad");
                strcpy(stops[route][1], "Jatrabari");
                strcpy(stops[route][2], "Motijheel");
                strcpy(stops[route][3], "Shahbag");
                strcpy(stops[route][4], "Banglamotor");
                strcpy(stops[route][5], "Palton");
                strcpy(stops[route][6], "Press Club");
                strcpy(stops[route][7], "Khulna");
                strcpy(stops[route][8], "Mugda");
                strcpy(stops[route][9], "Malibag");
                strcpy(stops[route][10], "Rampura");
                break;

            case 16:  // Route 17
                stopCounts[route] = 13;
                strcpy(stops[route][0], "Shyamoli");
                strcpy(stops[route][1], "Dhanmondi");
                strcpy(stops[route][2], "Shahbag");
                strcpy(stops[route][3], "Gulshan 1");
                strcpy(stops[route][4], "Motijheel");
                strcpy(stops[route][5], "Rampura");
                strcpy(stops[route][6], "Banasree");
                strcpy(stops[route][7], "New Market");
                strcpy(stops[route][8], "Shankar");
                strcpy(stops[route][9], "Dhanmondi");
                break;
            
            case 17:  // Route 18
                stopCounts[route] = 15;
                strcpy(stops[route][0], "Mirpur 10");
                strcpy(stops[route][1], "Kazipara");
                strcpy(stops[route][2], "Agargaon");
                strcpy(stops[route][3], "Shyamoli");
                strcpy(stops[route][4], "Asadgate");
                strcpy(stops[route][5], "Mohammadpur");
                strcpy(stops[route][6], "Science Lab");
                strcpy(stops[route][7], "Shahbag");
                strcpy(stops[route][8], "New Market");
                strcpy(stops[route][9], "Mogbazar");
                strcpy(stops[route][10], "Karwan Bazar");
                strcpy(stops[route][11], "Rampura");
                strcpy(stops[route][12], "Banani");
                strcpy(stops[route][13], "Mohakhali");
                strcpy(stops[route][14], "Uttara");
                break;
        }
    }
}
void showAllRoutes() {
    printf("\nAvailable Bus Routes:\n");
    for (int i = 0; i < MAX_ROUTES; i++) {
        printf("%d. %s\n", i + 1, routeNames[i]);
    }
}

void calculateFare() {
    FILE *fp;
    fp = fopen("bus_data.txt", "a");
    int routeChoice, start, end;
    showAllRoutes();

    printf("\nSelect Route Number (1-18): ");
    scanf("%d", &routeChoice);

    if (routeChoice < 1 || routeChoice > MAX_ROUTES) {
        printf("Invalid Route Number!\n");
        return;
    }

    printf("\nStops on %s:\n", routeNames[routeChoice - 1]);
    for (int i = 0; i < stopCounts[routeChoice - 1]; i++) {
        printf("%d. %s\n", i + 1, stops[routeChoice - 1][i]);
    }

    printf("Enter Starting Stop Number: ");
    scanf("%d", &start);
    printf("Enter Destination Stop Number: ");
    scanf("%d", &end);

    if (start < 1 || start > stopCounts[routeChoice - 1] || end < 1 || end > stopCounts[routeChoice - 1]) {
        printf("Invalid Stop Numbers!\n");
        return;
    }

    int distance = (end > start) ? (end - start) : (start - end);
    int fare = distance * 10;
    int time = distance * 5;

    separator();
    printf("Bus Name: %s\n", routeNames[routeChoice - 1]);
    printf("From: %s\n", stops[routeChoice - 1][start - 1]);
    printf("To: %s\n", stops[routeChoice - 1][end - 1]);
    printf("Total Stops: %d\n", distance);
    printf("Fare: %d Taka\n", fare);
    printf("Estimated Time: %d Minutes\n", time);
    separator();

    fprintf(fp, "Bus: %s | From: %s | To: %s | Stops: %d | Fare: %d Taka | Time: %d mins\n",
            routeNames[routeChoice - 1], stops[routeChoice - 1][start - 1], stops[routeChoice - 1][end - 1], distance, fare, time);

    fclose(fp);
}

// Show Route Stop Details
void showStopsDetails() {
    int routeChoice;
    showAllRoutes();
    printf("\nSelect Route Number to View Stops: ");
    scanf("%d", &routeChoice);

    if (routeChoice < 1 || routeChoice > MAX_ROUTES) {
        printf("Invalid Route Number!\n");
        return;
    }

    printf("\nStops on %s:\n", routeNames[routeChoice - 1]);
    for (int i = 0; i < stopCounts[routeChoice - 1]; i++) {
        printf("%d. %s\n", i + 1, stops[routeChoice - 1][i]);
    }
    separator();
}
int busAvailability[MAX_ROUTES][MAX_STOPS];

void initializeBusAvailability() {
    // Initialize bus availability for all routes with if-else statements
    if (0 == 0) {
        // Route 1: Anabil Super
        busAvailability[0][0] = 1; busAvailability[0][1] = 1; busAvailability[0][2] = 1;
        busAvailability[0][3] = 1; busAvailability[0][4] = 1; busAvailability[0][5] = 1;
        busAvailability[0][6] = 0; busAvailability[0][7] = 1; busAvailability[0][8] = 0;
        busAvailability[0][9] = 1; busAvailability[0][10] = 1; busAvailability[0][11] = 1;
    }
    else if (0 == 1) {
        // Route 2: Thikana Express Limited
        busAvailability[1][0] = 1; busAvailability[1][1] = 0; busAvailability[1][2] = 1;
        busAvailability[1][3] = 1; busAvailability[1][4] = 1; busAvailability[1][5] = 1;
        busAvailability[1][6] = 1; busAvailability[1][7] = 0; busAvailability[1][8] = 1;
        busAvailability[1][9] = 1;
    }
    else if (0 == 2) {
        // Route 3: RAIDA ENTERPRISE
        busAvailability[2][0] = 1; busAvailability[2][1] = 1; busAvailability[2][2] = 1;
        busAvailability[2][3] = 0; busAvailability[2][4] = 1; busAvailability[2][5] = 1;
        busAvailability[2][6] = 1; busAvailability[2][7] = 1; busAvailability[2][8] = 1;
        busAvailability[2][9] = 1;
    }
    else if (0 == 3) {
        // Route 4: Alif
        busAvailability[3][0] = 0; busAvailability[3][1] = 1; busAvailability[3][2] = 1;
        busAvailability[3][3] = 1; busAvailability[3][4] = 0; busAvailability[3][5] = 1;
        busAvailability[3][6] = 1; busAvailability[3][7] = 1; busAvailability[3][8] = 1;
    }
    else if (0 == 4) {
        // Route 5: Prajapati & Konok
        busAvailability[4][0] = 1; busAvailability[4][1] = 1; busAvailability[4][2] = 1;
        busAvailability[4][3] = 1; busAvailability[4][4] = 1; busAvailability[4][5] = 0;
        busAvailability[4][6] = 1; busAvailability[4][7] = 1; busAvailability[4][8] = 1;
        busAvailability[4][9] = 0;
    }
    else if (0 == 5) {
        // Route 6: BRTC
        busAvailability[5][0] = 1; busAvailability[5][1] = 1; busAvailability[5][2] = 1;
        busAvailability[5][3] = 1; busAvailability[5][4] = 1; busAvailability[5][5] = 1;
        busAvailability[5][6] = 1; busAvailability[5][7] = 1; busAvailability[5][8] = 0;
    }
    else if (0 == 6) {
        // Route 7: BOLAKA
        busAvailability[6][0] = 1; busAvailability[6][1] = 1; busAvailability[6][2] = 1;
        busAvailability[6][3] = 1; busAvailability[6][4] = 1; busAvailability[6][5] = 1;
        busAvailability[6][6] = 1; busAvailability[6][7] = 1; busAvailability[6][8] = 1;
    }
    else if (0 == 7) {
        // Route 8: LABBAYEK
        busAvailability[7][0] = 1; busAvailability[7][1] = 0; busAvailability[7][2] = 1;
        busAvailability[7][3] = 0; busAvailability[7][4] = 1; busAvailability[7][5] = 1;
        busAvailability[7][6] = 0; busAvailability[7][7] = 1; busAvailability[7][8] = 1;
    }
    else if (0 == 8) {
        // Route 9: TORONGO PLUS
        busAvailability[8][0] = 1; busAvailability[8][1] = 1; busAvailability[8][2] = 1;
        busAvailability[8][3] = 1; busAvailability[8][4] = 1; busAvailability[8][5] = 1;
        busAvailability[8][6] = 1; busAvailability[8][7] = 1; busAvailability[8][8] = 1;
        busAvailability[8][9] = 1; busAvailability[8][10] = 1; busAvailability[8][11] = 1;
        busAvailability[8][12] = 1;
    }
    if (0 == 9) {
        // Route 10: BAHON
        busAvailability[9][0] = 1; busAvailability[9][1] = 1; busAvailability[9][2] = 1;
        busAvailability[9][3] = 1; busAvailability[9][4] = 1; busAvailability[9][5] = 1;
        busAvailability[9][6] = 1; busAvailability[9][7] = 1; busAvailability[9][8] = 1;
        busAvailability[9][9] = 1; busAvailability[9][10] = 1; busAvailability[9][11] = 1;
        busAvailability[9][12] = 1; busAvailability[9][13] = 1;
    }
    else if (0 == 10) {
        // Route 11: NISORGO
        busAvailability[10][0] = 1; busAvailability[10][1] = 1; busAvailability[10][2] = 1;
        busAvailability[10][3] = 1; busAvailability[10][4] = 1; busAvailability[10][5] = 1;
        busAvailability[10][6] = 1; busAvailability[10][7] = 1; busAvailability[10][8] = 1;
        busAvailability[10][9] = 1; busAvailability[10][10] = 1; busAvailability[10][11] = 1;
        busAvailability[10][12] = 1; busAvailability[10][13] = 1; busAvailability[10][14] = 1;
    }
    else if (0 == 11) {
        // Route 12: SHOTABDI
        busAvailability[11][0] = 1; busAvailability[11][1] = 1; busAvailability[11][2] = 1;
        busAvailability[11][3] = 1; busAvailability[11][4] = 1; busAvailability[11][5] = 1;
        busAvailability[11][6] = 1; busAvailability[11][7] = 1; busAvailability[11][8] = 1;
        busAvailability[11][9] = 1; busAvailability[11][10] = 1; busAvailability[11][11] = 1;
        busAvailability[11][12] = 1; busAvailability[11][13] = 1;
    }
    else if (0 == 12) {
        // Route 13: CANTONMENT MINI SERVICE
        busAvailability[12][0] = 1; busAvailability[12][1] = 1; busAvailability[12][2] = 1;
        busAvailability[12][3] = 1; busAvailability[12][4] = 1; busAvailability[12][5] = 1;
        busAvailability[12][6] = 1; busAvailability[12][7] = 1; busAvailability[12][8] = 1;
    }
    else if (0 == 13) {
        // Route 14: RONGDHONU EXPRESS
        busAvailability[13][0] = 1; busAvailability[13][1] = 1; busAvailability[13][2] = 1;
        busAvailability[13][3] = 1; busAvailability[13][4] = 1; busAvailability[13][5] = 1;
        busAvailability[13][6] = 1; busAvailability[13][7] = 1; busAvailability[13][8] = 1;
        busAvailability[13][9] = 1; busAvailability[13][10] = 1; busAvailability[13][11] = 1;
    }
    else if (0 == 14) {
        // Route 15: BORAK PORIBOHON
        busAvailability[14][0] = 1; busAvailability[14][1] = 1;
    }
    else if (0 == 15) {
        // Route 16: RAJDHANI
        busAvailability[15][0] = 1; busAvailability[15][1] = 1; busAvailability[15][2] = 1;
        busAvailability[15][3] = 1; busAvailability[15][4] = 1; busAvailability[15][5] = 1;
        busAvailability[15][6] = 1; busAvailability[15][7] = 1; busAvailability[15][8] = 1;
        busAvailability[15][9] = 1; busAvailability[15][10] = 1; busAvailability[15][11] = 1;
    }
    else if (0 == 16) {
        // Route 17: SUPER BUS
        busAvailability[16][0] = 1; busAvailability[16][1] = 1; busAvailability[16][2] = 1;
        busAvailability[16][3] = 1; busAvailability[16][4] = 1; busAvailability[16][5] = 1;
        busAvailability[16][6] = 1; busAvailability[16][7] = 1; busAvailability[16][8] = 1;
        busAvailability[16][9] = 1; busAvailability[16][10] = 1; busAvailability[16][11] = 1;
    }
    else if (0 == 17) {
        // Route 18: DHAKA PORIBOHON
        busAvailability[17][0] = 1; busAvailability[17][1] = 1; busAvailability[17][2] = 1;
        busAvailability[17][3] = 1; busAvailability[17][4] = 1; busAvailability[17][5] = 1;
        busAvailability[17][6] = 1; busAvailability[17][7] = 1; busAvailability[17][8] = 1;
        busAvailability[17][9] = 1; busAvailability[17][10] = 1; busAvailability[17][11] = 1;
    }

}
void inputBusAvailability() {
    int routeChoice, stopChoice, availability;
    
    // Show all routes
    showAllRoutes();
    
    printf("\nSelect Route Number to Input Bus Availability: ");
    scanf("%d", &routeChoice);

    if (routeChoice < 1 || routeChoice > MAX_ROUTES) {
        printf("Invalid Route Number!\n");
        return;
    }

    // Display Stops for Selected Route
    printf("\nStops on %s:\n", routeNames[routeChoice - 1]);
    for (int i = 0; i < stopCounts[routeChoice - 1]; i++) {
        printf("%d. %s\n", i + 1, stops[routeChoice - 1][i]);
    }

    // Input availability for each stop on the selected route
    for (int i = 0; i < stopCounts[routeChoice - 1]; i++) {
        printf("\nIs the bus available at stop %s? (1 for Available, 0 for Not Available): ", stops[routeChoice - 1][i]);
        scanf("%d", &availability);

        // Ensure valid input (only 0 or 1)
        if (availability == 0 || availability == 1) {
            busAvailability[routeChoice - 1][i] = availability;
        } else {
            printf("Invalid input! Please enter 1 (available) or 0 (not available).\n");
            i--;  // Re-ask for the same stop if input is invalid
        }
    }

    printf("\nBus Availability Information has been updated.\n");
}
void displayBusAvailability() {
    int routeChoice, stopChoice;
    
    // Show all routes
    showAllRoutes();
    
    printf("\nSelect Route Number to Check Bus Availability: ");
    scanf("%d", &routeChoice);

    if (routeChoice < 1 || routeChoice > MAX_ROUTES) {
        printf("Invalid Route Number!\n");
        return;
    }

    // Display Stops for Selected Route
    printf("\nStops on %s:\n", routeNames[routeChoice - 1]);
    for (int i = 0; i < stopCounts[routeChoice - 1]; i++) {
        printf("%d. %s\n", i + 1, stops[routeChoice - 1][i]);
    }

    printf("\nEnter Stop Number to Check Availability: ");
    scanf("%d", &stopChoice);

    if (stopChoice < 1 || stopChoice > stopCounts[routeChoice - 1]) {
        printf("Invalid Stop Number!\n");
        return;
    }

    // Check and Display Bus Availability for Selected Stop
    if (busAvailability[routeChoice - 1][stopChoice - 1] == 1) {
        printf("The bus is available at %s.\n", stops[routeChoice - 1][stopChoice - 1]);
    } else {
        printf("Sorry, the bus is not available at %s.\n", stops[routeChoice - 1][stopChoice - 1]);
    }
}

// Function to input bus availability for all stops on a selected route


const char* stopNames[MAX_STOPS] = {
    "Shyamoli", "Gabtoli", "Jatrabari", "Sayedabad", "Khilgaon", 
    "Mohammadpur", "Tejgaon", "Kakrail", "Mirpur 1", "Mirpur 10", 
    "Bashundhara", "Shahbagh", "Dhanmondi", "Jatrabari", "Banasree",
    "Banani", "Motijheel", "Moghbazar", "Gulshan", "Uttara"
};

// Travel time data for each route
int estimatedTravelTime[MAX_ROUTES][MAX_STOPS] = {0};

// Function to initialize travel times for each route
void initializeEstimatedTravelTime(int routeId) {
    if (routeId == 1) {
        int times[] = {12, 18, 22, 28, 33, 38, 45, 52, 55, 65, 10,
             75, 80, 90, 76, 58, 60, 80, 64, 80, 45, 50, 55, 60};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 2) {
        int times[] = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 10,
             60, 65, 70, 75, 80, 85, 90, 95, 100, 40, 42, 44, 46};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 3) {
        int times[] = {14, 16, 24, 30, 36, 40, 42, 48, 54, 60, 
            15, 65, 70, 75, 80, 85, 90, 95, 100, 110, 50, 55, 60, 65};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 4) {
        int times[] = {11, 17, 21, 26, 32, 37, 40, 45, 50, 55, 12,
             60, 65, 70, 75, 80, 85, 90, 95, 105, 45, 48, 52, 55};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 5) {
        int times[] = {9, 14, 18, 23, 27, 31, 35, 40, 45, 50, 13,
             55, 60, 65, 70, 75, 80, 85, 90, 95, 38, 41, 45, 48};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 6) {
        int times[] = {13, 19, 23, 29, 35, 39, 44, 49, 54,
             59, 14, 64, 69, 74, 79, 84, 89, 94, 99, 104, 43, 46, 49, 53};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 7) {
        int times[] = {16, 22, 26, 32, 37, 42, 48, 53, 58,
             63, 17, 68, 73, 78, 83, 88, 93, 98, 103, 108, 46, 49, 52, 56};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 8) {
        int times[] = {10, 15, 20, 25, 30, 35, 40, 45, 50, 
            55, 10, 60, 65, 70, 75, 80, 85, 90, 95, 100, 40, 42, 44, 46};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 9) {
        int times[] = {14, 16, 24, 30, 36, 40, 42, 48, 54, 60,
             15, 65, 70, 75, 80, 85, 90, 95, 100, 110, 50, 55, 60, 65};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 10) {
        int times[] = {11, 17, 21, 26, 32, 37, 40, 45, 50, 55,
             12, 60, 65, 70, 75, 80, 85, 90, 95, 105, 45, 48, 52, 55};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 11) {
        int times[] = {9, 14, 18, 23, 27, 31, 35, 40, 45, 50,
             13, 55, 60, 65, 70, 75, 80, 85, 90, 95, 38, 41, 45, 48};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 12) {
        int times[] = {13, 19, 23, 29, 35, 39, 44, 49, 54, 59,
             14, 64, 69, 74, 79, 84, 89, 94, 99, 104, 43, 46, 49, 53};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 13) {
        int times[] = {16, 22, 26, 32, 37, 42, 48, 53, 58, 63, 17,
             68, 73, 78, 83, 88, 93, 98, 103, 108, 46, 49, 52, 56};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 14) {
        int times[] = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 10,
             60, 65, 70, 75, 80, 85, 90, 95, 100, 40, 42, 44, 46};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 15) {
        int times[] = {14, 16, 24, 30, 36, 40, 42, 48, 54, 60, 15,
             65, 70, 75, 80, 85, 90, 95, 100, 110, 50, 55, 60, 65};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    else if (routeId == 16) {
        int times[] = {11, 17, 21, 26, 32, 37, 40, 45, 50, 55, 12,
             60, 65, 70, 75, 80, 85, 90, 95, 105, 45, 48, 52, 55};

        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }

    else if (routeId == 17) {
        int times[] = {9, 14, 18, 23, 27, 31, 35, 40, 45, 50, 13, 
            55, 60, 65, 70, 75, 80, 85, 90, 95, 38, 41, 45, 48};
        for (int i = 0; i < MAX_STOPS - 1; i++) {
            estimatedTravelTime[routeId - 1][i] = times[i];
        }
    }
    
}
void inputTravelTime() {
    int route, startStop, endStop, time;
    printf("Enter route number (1 to %d): ", MAX_ROUTES);
    scanf("%d", &route);
    printf("Enter start stop number (1 to %d): ", MAX_STOPS);
    scanf("%d", &startStop);
    printf("Enter end stop number (2 to %d): ", MAX_STOPS);
    scanf("%d", &endStop);
    printf("Enter estimated travel time (in minutes): ");
    scanf("%d", &time);
    
    if (route >= 1 && route <= MAX_ROUTES &&
        startStop >= 1 && startStop < MAX_STOPS &&
        endStop > startStop && endStop <= MAX_STOPS) {
        estimatedTravelTime[route - 1][startStop - 1] = time;  // Update the travel time
        printf("Travel time between Stop %d and Stop %d updated to %d minutes.\n", startStop, endStop, time);
    } else {
        printf("Invalid input. Please try again.\n");
    }
}


void displayEstimatedTravelTime(int routeId) {
    printf("Estimated travel times for Route %d:\n", routeId);
    for (int i = 0; i < MAX_STOPS - 1; i++) {
        if (estimatedTravelTime[routeId - 1][i] > 0) {
            printf("From %s to %s: %d minutes\n", stopNames[i], stopNames[i + 1], estimatedTravelTime[routeId - 1][i]);
        }
    }
}
void calculateDistance() {
    int startStop, endStop;

    printf("\n===== Available Stops =====\n");
    printf("1. Shyamoli\n2. Gabtoli\n3. Jatrabari\n4. Sayedabad\n5. Khilgaon\n");
    printf("6. Mohammadpur\n7. Tejgaon\n8. Kakrail\n9. Mirpur 1\n10. Mirpur 10\n");
    printf("11. Bashundhara\n12. Shahbagh\n13. Dhanmondi\n14. Jatrabari\n15. Banasree\n");
    printf("16. Banani\n17. Motijheel\n18. Moghbazar\n19. Gulshan\n20. Uttara\n");

    printf("\nEnter starting stop number: ");
    scanf("%d", &startStop);
    printf("Enter ending stop number: ");
    scanf("%d", &endStop);

    if (startStop < 1 || startStop > 20 || endStop < 1 || endStop > 20) {
        printf("Invalid stop selection!\n");
        return;
    }

    if (startStop > endStop) {
        int temp = startStop;
        startStop = endStop;
        endStop = temp;
    }

    printf("\nFrom: ");
    if (startStop == 1) { printf("Shyamoli\n"); }
    else if (startStop == 2) { printf("Gabtoli\n"); }
    else if (startStop == 3) { printf("Jatrabari\n"); }
    else if (startStop == 4) { printf("Sayedabad\n"); }
    else if (startStop == 5) { printf("Khilgaon\n"); }
    else if (startStop == 6) { printf("Mohammadpur\n"); }
    else if (startStop == 7) { printf("Tejgaon\n"); }
    else if (startStop == 8) { printf("Kakrail\n"); }
    else if (startStop == 9) { printf("Mirpur 1\n"); }
    else if (startStop == 10) { printf("Mirpur 10\n"); }
    else if (startStop == 11) { printf("Bashundhara\n"); }
    else if (startStop == 12) { printf("Shahbagh\n"); }
    else if (startStop == 13) { printf("Dhanmondi\n"); }
    else if (startStop == 14) { printf("Jatrabari\n"); }
    else if (startStop == 15) { printf("Banasree\n"); }
    else if (startStop == 16) { printf("Banani\n"); }
    else if (startStop == 17) { printf("Motijheel\n"); }
    else if (startStop == 18) { printf("Moghbazar\n"); }
    else if (startStop == 19) { printf("Gulshan\n"); }
    else if (startStop == 20) { printf("Uttara\n"); }

    printf("To: ");
    if (endStop == 1) { printf("Shyamoli\n"); }
    else if (endStop == 2) { printf("Gabtoli\n"); }
    else if (endStop == 3) { printf("Jatrabari\n"); }
    else if (endStop == 4) { printf("Sayedabad\n"); }
    else if (endStop == 5) { printf("Khilgaon\n"); }
    else if (endStop == 6) { printf("Mohammadpur\n"); }
    else if (endStop == 7) { printf("Tejgaon\n"); }
    else if (endStop == 8) { printf("Kakrail\n"); }
    else if (endStop == 9) { printf("Mirpur 1\n"); }
    else if (endStop == 10) { printf("Mirpur 10\n"); }
    else if (endStop == 11) { printf("Bashundhara\n"); }
    else if (endStop == 12) { printf("Shahbagh\n"); }
    else if (endStop == 13) { printf("Dhanmondi\n"); }
    else if (endStop == 14) { printf("Jatrabari\n"); }
    else if (endStop == 15) { printf("Banasree\n"); }
    else if (endStop == 16) { printf("Banani\n"); }
    else if (endStop == 17) { printf("Motijheel\n"); }
    else if (endStop == 18) { printf("Moghbazar\n"); }
    else if (endStop == 19) { printf("Gulshan\n"); }
    else if (endStop == 20) { printf("Uttara\n"); }

    int totalDistance = (endStop - startStop) * 2;
    printf("Distance: %d km\n", totalDistance);
}
void Bus_calculateFare() {
    int distance, passengerType;
    
    printf("\nEnter distance in km: ");
    scanf("%d", &distance);

    int fare;
    if (distance <= 2) {
        fare = 10;
    } else if (distance <= 5) {
        fare = 20;
    } else if (distance <= 10) {
        fare = 30;
    } else {
        fare = 50;
    }

    printf("\nSelect Passenger Type:\n");
    printf("1. Student (50%% Discount)\n");
    printf("2. General Public (No Discount)\n");
    printf("Enter choice: ");
    scanf("%d", &passengerType);

    if (passengerType == 1) {
        fare /= 2; // Apply 50% discount for students
    } else if (passengerType != 2) {
        printf("Invalid choice! Defaulting to general fare.\n");
    }

    printf("Estimated fare: %d BDT\n", fare);
}
void printTicket() {
    FILE *ticket = fopen("ticket.txt", "w");
    if (ticket == NULL) {
        printf("Error creating ticket file!\n");
        return;
    }

    char type[20], bus[50], from[50], to[50], fareStr[10];
    int fare;

    printf("Enter Passenger Type (Student/General): ");
    fgets(type, sizeof(type), stdin);
    type[strcspn(type, "\n")] = '\0'; // Remove newline character

    printf("Enter Bus Name: ");
    fgets(bus, sizeof(bus), stdin);
    bus[strcspn(bus, "\n")] = '\0';

    printf("Enter Starting Stop: ");
    fgets(from, sizeof(from), stdin);
    from[strcspn(from, "\n")] = '\0';

    printf("Enter Destination Stop: ");
    fgets(to, sizeof(to), stdin);
    to[strcspn(to, "\n")] = '\0';

    printf("Enter Fare (in BDT): ");
    fgets(fareStr, sizeof(fareStr), stdin);
    fare = atoi(fareStr);

    time_t now = time(NULL);
    char *dt = ctime(&now);

    fprintf(ticket, "------------------------------\n");
    fprintf(ticket, "        BUS KOI TICKET        \n");
    fprintf(ticket, "------------------------------\n");
    fprintf(ticket, "Date & Time : %s", dt);
    fprintf(ticket, "Passenger   : %s\n", type);
    fprintf(ticket, "Bus         : %s\n", bus);
    fprintf(ticket, "From        : %s\n", from);
    fprintf(ticket, "To          : %s\n", to);
    fprintf(ticket, "Fare        : %d BDT\n", fare);
    fprintf(ticket, "------------------------------\n");
    fprintf(ticket, "  Thank you for using Bus Koi\n");
    fprintf(ticket, "------------------------------\n");

    fclose(ticket);
    printf("Ticket saved to 'ticket.txt'\n");
}
void collectFeedback() {
    FILE *fp;
    fp = fopen("feedback.txt", "a");  // Open the file in append mode to save feedback

    if (fp == NULL) {
        printf("Error opening feedback file!\n");
        return;
    }

    int rating;
    int feedbackChoice;
    char comment[100];  // To store the feedback comment

    // Collect the feedback rating (1-5)
    printf("\nPlease rate your experience from 1 (Poor) to 5 (Excellent): ");
    scanf("%d", &rating);
    
    // Validate rating input
    if (rating < 1 || rating > 5) {
        printf("Invalid rating! Please enter a number between 1 and 5.\n");
        fclose(fp);
        return;
    }

    // Provide a menu for predefined feedback options
    printf("\nSelect Feedback Type:\n");
    printf("1. Excellent\n");
    printf("2. Good\n");
    printf("3. Average\n");
    printf("4. Poor\n");
    printf("5. Fare\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &feedbackChoice);

    // Use switch-case to set the comment based on user selection
    switch (feedbackChoice) {
        case 1:
            strcpy(comment, "Excellent");
            break;
        case 2:
            strcpy(comment, "Good");
            break;
        case 3:
            strcpy(comment, "Average");
            break;
        case 4:
            strcpy(comment, "Poor");
            break;
        case 5:
            strcpy(comment, "Fare");
            break;
        default:
            printf("Invalid choice! No feedback saved.\n");
            fclose(fp);
            return;
    }

    // Save the feedback to the file
    fprintf(fp, "Rating: %d/5\nFeedback: %s\n\n", rating, comment);
    
    printf("\nThank you for your feedback!\n");

    fclose(fp);
}

int main() {
    // Initialize routes and travel times
    initializeRoutes();

    int choice;
    int routeId;

    char input[100];

    while (1) {
        displayMenu();
        printf("Enter Your Choice: ");
        fflush(stdin); // Clear leftover input
        fgets(input, sizeof(input), stdin);

        // Validate: check if input is a number
        int valid = 1;
        for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
            if (input[i] < '0' || input[i] > '9') {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Invalid input! Please enter a number between 1 and 11.\n");
            continue;
        }

        choice = atoi(input);
        // Handle menu options
        switch (choice) {
            case 1:
                showAllRoutes();
                break;
            case 2:
                calculateFare();
                break;
            case 3:
                showStopsDetails();
                break;
            case 4:
                Bus_calculateFare();
                break;    
            
            case 5:
                inputBusAvailability();
                break;
            case 6:
                displayBusAvailability();
                break;
                case 7:
                inputTravelTime();
                break;
            case 8:
                printf("Enter route ID (1-%d): ", MAX_ROUTES);
                scanf("%d", &routeId);

                if (routeId >= 1 && routeId <= MAX_ROUTES) {
                    initializeEstimatedTravelTime(routeId);
                    displayEstimatedTravelTime(routeId);
                } else {
                    printf("Invalid route ID! Please try again.\n");
                }
                break;
            
            
            case 9:
                 calculateDistance();
                break;
              
                case 10:
                collectFeedback();
                break; 
                case 11:
                   printTicket();
                        break; 
               
            case 12:
                printf("Thank you for using Bus Koi! Exiting...\n");
                return 0;
            default:
                printf("Invalid Choice! Please Try Again.\n");
        }
    }

    return 0;
}









