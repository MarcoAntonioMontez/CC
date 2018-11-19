/*
 * lab1_simul.c
 *
 * Code generation for model "lab1_simul".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Oct 10 08:32:56 2018
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab1_simul.h"
#include "lab1_simul_private.h"
#include "lab1_simul_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double RTWinBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "National_Instruments/PCI-MIO-16E-4", 4294967295U, 6, RTWinBoardOptions0 },
};

/* Block signals (auto storage) */
B_lab1_simul_T lab1_simul_B;

/* Block states (auto storage) */
DW_lab1_simul_T lab1_simul_DW;

/* Real-time model */
RT_MODEL_lab1_simul_T lab1_simul_M_;
RT_MODEL_lab1_simul_T *const lab1_simul_M = &lab1_simul_M_;

/* Model output function */
void lab1_simul_output(void)
{
  real_T temp;

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = lab1_simul_P.SignalGenerator_Frequency * lab1_simul_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    lab1_simul_B.SignalGenerator = lab1_simul_P.SignalGenerator_Amplitude;
  } else {
    lab1_simul_B.SignalGenerator = -lab1_simul_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab1_simul_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab1_simul_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab1_simul_P.AnalogOutput_Channels,
                     &lab1_simul_B.SignalGenerator, &parm);
    }
  }

  /* S-Function Block: <Root>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) lab1_simul_P.AnalogInput1_RangeMode;
    parm.rangeidx = lab1_simul_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &lab1_simul_P.AnalogInput1_Channels,
                   &lab1_simul_B.AnalogInput1, &parm);
  }

  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) lab1_simul_P.AnalogInput_RangeMode;
    parm.rangeidx = lab1_simul_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &lab1_simul_P.AnalogInput_Channels,
                   &lab1_simul_B.AnalogInput, &parm);
  }
}

/* Model update function */
void lab1_simul_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab1_simul_M->Timing.clockTick0)) {
    ++lab1_simul_M->Timing.clockTickH0;
  }

  lab1_simul_M->Timing.t[0] = lab1_simul_M->Timing.clockTick0 *
    lab1_simul_M->Timing.stepSize0 + lab1_simul_M->Timing.clockTickH0 *
    lab1_simul_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab1_simul_M->Timing.clockTick1)) {
      ++lab1_simul_M->Timing.clockTickH1;
    }

    lab1_simul_M->Timing.t[1] = lab1_simul_M->Timing.clockTick1 *
      lab1_simul_M->Timing.stepSize1 + lab1_simul_M->Timing.clockTickH1 *
      lab1_simul_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void lab1_simul_initialize(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab1_simul_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab1_simul_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab1_simul_P.AnalogOutput_Channels,
                     &lab1_simul_P.AnalogOutput_InitialValue, &parm);
    }
  }
}

/* Model terminate function */
void lab1_simul_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab1_simul_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab1_simul_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &lab1_simul_P.AnalogOutput_Channels,
                     &lab1_simul_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  lab1_simul_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab1_simul_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  lab1_simul_initialize();
}

void MdlTerminate(void)
{
  lab1_simul_terminate();
}

/* Registration function */
RT_MODEL_lab1_simul_T *lab1_simul(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab1_simul_M, 0,
                sizeof(RT_MODEL_lab1_simul_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab1_simul_M->solverInfo,
                          &lab1_simul_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab1_simul_M->solverInfo, &rtmGetTPtr(lab1_simul_M));
    rtsiSetStepSizePtr(&lab1_simul_M->solverInfo,
                       &lab1_simul_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&lab1_simul_M->solverInfo, (&rtmGetErrorStatus
      (lab1_simul_M)));
    rtsiSetRTModelPtr(&lab1_simul_M->solverInfo, lab1_simul_M);
  }

  rtsiSetSimTimeStep(&lab1_simul_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&lab1_simul_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab1_simul_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    lab1_simul_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab1_simul_M->Timing.sampleTimes = (&lab1_simul_M->Timing.sampleTimesArray[0]);
    lab1_simul_M->Timing.offsetTimes = (&lab1_simul_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab1_simul_M->Timing.sampleTimes[0] = (0.0);
    lab1_simul_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    lab1_simul_M->Timing.offsetTimes[0] = (0.0);
    lab1_simul_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(lab1_simul_M, &lab1_simul_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab1_simul_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    lab1_simul_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab1_simul_M, 6.0);
  lab1_simul_M->Timing.stepSize0 = 0.001;
  lab1_simul_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  lab1_simul_M->Sizes.checksums[0] = (1432406726U);
  lab1_simul_M->Sizes.checksums[1] = (1730530650U);
  lab1_simul_M->Sizes.checksums[2] = (3378078219U);
  lab1_simul_M->Sizes.checksums[3] = (1430651595U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab1_simul_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab1_simul_M->extModeInfo,
      &lab1_simul_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab1_simul_M->extModeInfo, lab1_simul_M->Sizes.checksums);
    rteiSetTPtr(lab1_simul_M->extModeInfo, rtmGetTPtr(lab1_simul_M));
  }

  lab1_simul_M->solverInfoPtr = (&lab1_simul_M->solverInfo);
  lab1_simul_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&lab1_simul_M->solverInfo, 0.001);
  rtsiSetSolverMode(&lab1_simul_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab1_simul_M->ModelData.blockIO = ((void *) &lab1_simul_B);
  (void) memset(((void *) &lab1_simul_B), 0,
                sizeof(B_lab1_simul_T));

  /* parameters */
  lab1_simul_M->ModelData.defaultParam = ((real_T *)&lab1_simul_P);

  /* states (dwork) */
  lab1_simul_M->ModelData.dwork = ((void *) &lab1_simul_DW);
  (void) memset((void *)&lab1_simul_DW, 0,
                sizeof(DW_lab1_simul_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab1_simul_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab1_simul_M->Sizes.numContStates = (0);/* Number of continuous states */
  lab1_simul_M->Sizes.numY = (0);      /* Number of model outputs */
  lab1_simul_M->Sizes.numU = (0);      /* Number of model inputs */
  lab1_simul_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lab1_simul_M->Sizes.numSampTimes = (2);/* Number of sample times */
  lab1_simul_M->Sizes.numBlocks = (5); /* Number of blocks */
  lab1_simul_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  lab1_simul_M->Sizes.numBlockPrms = (19);/* Sum of parameter "widths" */
  return lab1_simul_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
