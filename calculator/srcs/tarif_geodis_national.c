#include "main.h"

double	tarif(int zoneMessagerie, int poids, int mode, int corse)
{
	int			tranchePoids;
	int			count;
	double		prixBase;
	double		tableMessagerie[12][16] =
	{
		{ 11.87, 13.00, 14.10, 15.21, 16.32, 19.63, 22.92, 24.92, 26.95, 28.95, 30.97, 32.96, 32.96, 31.31, 29.76, 28.26 },
		{ 19.88, 22.39, 24.91, 27.44, 29.96, 33.30, 36.66, 40.03, 43.38, 46.75, 50.11, 53.46, 53.46, 50.79, 48.24, 45.83 },
		{ 21.86, 25.39, 28.93, 32.45, 35.98, 40.62, 45.25, 49.90, 54.52, 59.16, 63.78, 68.42, 68.42, 65.00, 61.75, 58.67 },
		{ 23.38, 27.38, 31.37, 35.36, 39.35, 44.50, 49.67, 54.83, 59.99, 65.14, 70.30, 75.46, 75.46, 71.20, 68.10, 64.70 },
		{ 24.90, 29.26, 33.62, 37.95, 42.31, 47.81, 53.30, 58.78, 64.29, 69.77, 75.25, 80.74, 80.74, 76.72, 72.87, 69.24 },
		{ 26.42, 31.24, 36.07, 40.88, 45.71, 51.54, 57.32, 63.16, 68.94, 74.78, 80.59, 86.40, 86.40, 82.08, 77.99, 74.07 },
		{ 27.59, 33.02, 38.49, 43.94, 49.37, 55.39, 61.44, 67.46, 73.50, 79.52, 85.55, 91.58, 91.58, 87.01, 82.66, 78.52 },
		{ 27.76, 34.03, 40.29, 46.55, 52.83, 59.01, 65.20, 71.40, 77.60, 83.78, 89.97, 96.15, 96.15, 91.37, 86.79, 82.45 },
		{ 27.95, 35.09, 42.23, 49.38, 56.52, 62.88, 69.23, 75.57, 81.91, 88.27, 94.63, 100.98, 100.98, 95.92, 91.13, 86.57 },
		{ 28.10, 36.20, 44.29, 52.39, 60.48, 66.98, 73.49, 79.99, 86.51, 93.01, 99.53, 106.02, 106.02, 100.73, 95.68, 90.91 },
		{ 28.29, 37.24, 46.20, 55.14, 64.12, 70.85, 77.61, 84.33, 91.08, 97.83, 104.58, 111.33, 111.33, 105.76, 100.48, 95.46 },
		{ 28.46, 38.17, 47.89, 57.60, 67.30, 74.07, 80.85, 87.60, 94.38, 101.13, 107.91, 114.67, 114.67, 108.93, 103.48, 98.31 }
	};
	double		tableMessagerieExpress[7][16] =
	{
		{ 11.81, 12.90, 14.01, 15.10, 16.21, 19.49, 22.78, 26.06, 29.35, 32.63, 35.92, 39.21, 39.21 },
		{ 19.74, 22.33, 24.91, 27.49, 30.08, 35.92, 41.76, 47.59, 53.43, 59.27, 65.10, 70.95, 70.95 },
		{ 21.72, 27.06, 32.40, 37.75, 43.10, 50.12, 57.14, 64.14, 71.17, 78.18, 85.20, 92.23, 92.23 },
		{ 23.23, 29.62, 36.01, 42.41, 48.81, 58.05, 67.28, 76.54, 85.77, 95.03, 104.27, 113.52, 113.52 },
		{ 24.74, 32.26, 39.78, 47.29, 54.82, 66.25, 77.67, 89.10, 100.52, 111.95, 123.38, 134.81, 134.81 },
		{ 26.24, 34.84, 43.46, 52.07, 60.69, 74.31, 87.94, 101.57, 115.18, 128.83, 142.45, 156.09, 156.09 },
		{ 27.40, 37.83, 48.26, 58.70, 69.13, 84.58, 100.05, 115.52, 130.98, 146.45, 161.91, 177.35, 177.35 }
	};
	// double		tableMessagerieCorse[12][16] =
	// {
	// 	{ 50.08, 53.58, 65.66, 68.15, 79.03, 91.32, 105.96, 116.70, 122.66, 131.01, 138.16, 139.32, 139.32, 137.38, 135.54, 133.79 },
	// 	{ 60.47, 64.63, 78.39, 82.52, 95.08, 107.39, 122.12, 134.46, 142.01, 151.92, 160.67, 163.42, 163.42, 160.27, 157.28, 154.45 },
	// 	{ 62.81, 68.17, 83.09, 88.46, 102.17, 116.01, 132.22, 146.06, 155.10, 166.53, 176.76, 181.03, 181.03, 177.01, 173.18, 169.54 },
	// 	{ 64.61, 70.50, 85.97, 91.87, 106.13, 120.57, 137.42, 151.86, 161.52, 173.57, 184.43, 189.30, 189.30, 184.87, 180.66, 176.67 },
	// 	{ 66.41, 72.71, 88.61, 94.93, 109.63, 124.46, 141.70, 156.52, 166.57, 179.03, 190.25, 195.52, 195.52, 190.79, 186.26, 181.99 },
	// 	{ 68.18, 75.05, 91.49, 98.36, 113.62, 128.83, 146.44, 161.67, 172.08, 184.90, 196.53, 202.18, 202.18, 197.10, 192.28, 187.68 },
	// 	{ 69.54, 77.15, 94.33, 101.94, 117.92, 133.39, 151.25, 166.73, 177.42, 190.50, 202.39, 208.27, 208.27, 202.89, 197.78, 192.91 },
	// 	{ 69.76, 78.33, 96.48, 105.03, 121.99, 137.65, 155.69, 171.37, 182.24, 195.50, 207.59, 213.65, 213.65, 208.02, 202.64, 197.54 },
	// 	{ 69.96, 79.58, 98.74, 108.36, 126.34, 142.18, 160.43, 176.26, 187.34, 200.79, 213.05, 219.31, 219.31, 213.40, 207.74, 202.39 },
	// 	{ 70.17, 80.89, 101.17, 111.90, 131.00, 147.02, 165.44, 181.47, 192.73, 206.36, 218.80, 225.26, 225.26, 219.03, 213.10, 207.46 },
	// 	{ 70.37, 82.12, 103.41, 115.15, 135.26, 151.57, 170.28, 186.58, 198.12, 212.04, 224.76, 231.51, 231.51, 224.95, 218.74, 212.82 },
	// 	{ 70.59, 83.20, 105.40, 118.03, 139.03, 155.37, 174.10, 190.43, 201.97, 215.92, 228.67, 235.44, 235.44, 228.69, 222.26, 216.19 }
	// };
	// double		tableMessagerieExpressCorse[7][16] =
	// {
	// 	{ 51.15, 54.70, 80.83, 82.12, 99.23, 117.77, 137.45, 165.02, 186.95, 205.50, 228.56, 248.23, 247.09 },
	// 	{ 60.47, 65.78, 93.67, 96.70, 115.56, 137.10, 159.77, 190.35, 215.28, 236.83, 262.89, 285.58, 284.45 },
	// 	{ 62.80, 71.36, 102.47, 108.76, 130.88, 153.80, 177.86, 209.83, 236.16, 259.09, 286.54, 310.62, 309.49 },
	// 	{ 64.59, 74.37, 106.73, 114.26, 137.58, 163.14, 189.81, 224.40, 253.36, 278.90, 308.97, 335.66, 334.52 },
	// 	{ 66.34, 77.47, 111.16, 120.00, 144.65, 172.79, 202.02, 239.19, 270.69, 298.81, 331.44, 360.70, 359.57 },
	// 	{ 68.13, 80.52, 115.48, 125.63, 151.56, 182.26, 214.11, 253.85, 287.96, 318.66, 353.88, 385.73, 384.60 },
	// 	{ 69.50, 84.04, 121.14, 133.41, 161.50, 194.35, 228.36, 270.27, 306.53, 339.41, 376.79, 410.78, 409.65 }
	// };

	count = 0;
	zoneMessagerie--;
	if (poids >= 0 && poids <= 4)
		tranchePoids = 0;
	else if (poids >= 5 && poids <= 9)
		tranchePoids = 1;
	else if (poids >= 10 && poids <= 14)
		tranchePoids = 2;
	else if (poids >= 15 && poids <= 19)
		tranchePoids = 3;
	else if (poids >= 20 && poids <= 29)
		tranchePoids = 4;
	else if (poids >= 30 && poids <= 39)
		tranchePoids = 5;
	else if (poids >= 40 && poids <= 49)
		tranchePoids = 6;
	else if (poids >= 50 && poids <= 59)
		tranchePoids = 7;
	else if (poids >= 60 && poids <= 69)
		tranchePoids = 8;
	else if (poids >= 70 && poids <= 79)
		tranchePoids = 9;
	else if (poids >= 80 && poids <= 89)
		tranchePoids = 10;
	else if (poids >= 90 && poids <= 99)
		tranchePoids = 11;
	if (!mode)
	{
		if (poids >= 100 && poids <= 199)
			tranchePoids = 12;
		else if (poids >= 200 && poids <= 299)
			tranchePoids = 13;
		else if (poids >= 300 && poids <= 499)
			tranchePoids = 14;
		else if (poids >= 500 && poids <= 1000)
			tranchePoids = 15;
	}
	else
	{
		if (poids >= 100 && poids <= 1000)
			tranchePoids = 12;
	}
	if (!corse)
	{
		if (!mode)
		{
			printf("\nZone %d\n", zoneMessagerie);
			printf("TP %d\n", tranchePoids);
			printf("%f\n", tableMessagerie[zoneMessagerie][tranchePoids]);
			prixBase = tableMessagerie[zoneMessagerie][tranchePoids];
			prixBase = read_file("ressources/table_messagerie.csv", zoneMessagerie, tranchePoids);
		}
		else
		{
			printf("\nZone %d\n", zoneMessagerie);
			printf("TP %d\n", tranchePoids);
			printf("real = %f\n", tableMessagerieExpress[zoneMessagerie][tranchePoids]);
			//prixBase = tableMessagerieExpress[zoneMessagerie][tranchePoids];
			prixBase = read_file("ressources/table_messagerie_express.csv", zoneMessagerie, tranchePoids);
		}
	}
	else
	{
		if (!mode)
			prixBase = read_file("ressources/table_messagerie_corse.csv", zoneMessagerie, tranchePoids);
		else
			prixBase = read_file("ressources/table_messagerie_express_corse.csv", zoneMessagerie, tranchePoids);
	}
	return poids > 100 ? (prixBase * (double)(poids / 100.00)) : (prixBase);
}
