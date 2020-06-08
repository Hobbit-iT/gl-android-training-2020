package com.ledctrlservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

import vendor.gl.hardware.ledctrl.V1_0.ILedCtrl;

public class LedCtrlService extends Service {
    ILedCtrl ledctrl;

    public LedCtrlService() {
    }

    ILedCtrlInterface.Stub ledService = new ILedCtrlInterface.Stub() {
        @Override
        public int setLED(int led, int state) {
            try {
                return ledctrl.setLED(led, state);
            } catch (Exception e) {
                e.printStackTrace();
            }
            return 0;
        };
    };

    @Override
    public IBinder onBind(Intent intent) {
        return ledService;
    }

    @Override
    public void onCreate() {
        try {
            ledctrl = ILedCtrl.getService(true);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
