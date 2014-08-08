/*
 * @file MATrader.mq5
 * @author Simon Lee (silee001@gmail.com)
 * @brief Trades Forex based on Long and short term trends
 *
 */

#property copyright "Simon Lee"
#property link      ""
#property version   "1.00"
#property strict

/* ************************************************************************** */
/* Input                                                                      */
input int MA_Long  = 30;
input int MA_Short = 10;


int iMA_Handle_Long = 0;
int iMA_Handle_Short = 0;
/* ************************************************************************** */
/* Initialise                                                                 */
int OnInit() {
  bool init_success = true;

  /* ************************************************************************ */
  /* Add MA Indicators                                                        */
  iMA_Handle_Long = iMA(Symbol(),0,MA_Long,0,MODE_SMA,PRICE_MEDIAN);
    // Symbol name, Period, Averaging period, Horizontal shift, Smoothing type, Type of price or handle
  ChartIndicatorAdd(0,0,iMA_Handle_Long);
    // Chart ID, Number of Subwindow, Handle of the indicator

  iMA_Handle_Short = iMA(Symbol(),0,MA_Short,0,MODE_SMA,PRICE_MEDIAN);
    // Symbol name, Period, Averaging period, Horizontal shift, Smoothing type, Type of price or handle
  ChartIndicatorAdd(0,0,iMA_Handle_Short);
    // Chart ID, Number of Subwindow, Handle of the indicator

  if(init_success == true) {
    return(INIT_SUCCEEDED);
  }

  else {
    Alert("Error in Initialising");
    return(INIT_FAILED);
  }

}



/* ************************************************************************** */
/* On Tick                                                                    */
void OnTick() {

}


/* ************************************************************************** */
/* Deinitialise                                                               */
void OnDeinit(const int reason) {
   ChartIndicatorDelete(0,0,iMA_Handle_Long);
   ChartIndicatorDelete(0,0,iMA_Handle_Short);
}
