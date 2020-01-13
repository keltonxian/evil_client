package com.evil.game;

import org.cocos2dx.lua.AppActivity;

import com.evil.game.R;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

public class PushService extends Service {
	
	@Override
	public IBinder onBind(Intent arg0) {
		// TODO Auto-generated method stub
		return null;
	}
	
	@Override
	public void onStart(Intent intent, int startId)
	{
		Log.e("EvilCard", "PushService onStart");
		super.onStart(intent, startId);
		final CharSequence title = intent.getCharSequenceExtra("title");
		final CharSequence detail = intent.getCharSequenceExtra("detail");
		final int time = intent.getIntExtra("time", 0);
		new Thread(new Runnable() {

			@Override
			public void run() {
				// TODO Auto-generated method stub
				Log.e("EvilCard", "notifacation 2");
				try {
					long waitTime = time; // ms
					Log.e("EvilCard", "notifacation waitTime: "+waitTime);
					Thread.sleep(waitTime);
					NotificationManager nm = (NotificationManager)getSystemService(Context.NOTIFICATION_SERVICE);
					
					int notificationIcon=R.drawable.icon;  
                    CharSequence notificationTitle = title;  
                    long when = System.currentTimeMillis();
                    Notification n = new Notification(notificationIcon, notificationTitle, when);
                    n.defaults = Notification.DEFAULT_SOUND;
                    
                    Intent intent = new Intent(getApplicationContext(), AppActivity.class);
    				PendingIntent pi= PendingIntent.getActivity(getApplicationContext(), 0, intent, 0);
    				String iTitle = String.valueOf(title);
    				String content = String.valueOf(detail);
    				n.setLatestEventInfo(getApplicationContext(), iTitle, content, pi);
    				
                    if(n != null)  
                    {  
                        Log.e("EvilCard", "notifacation is ok");  
                        nm.notify(1, n);  
                    }
                    stopSelf();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}).start();
	}
	
	@Override
	public void onCreate() {
		Log.e("EvilCard", "PushService onCreate");
		super.onCreate();
	}
	
    @Override
    public void onDestroy() {
    	super.onDestroy();
		System.exit(0);
    }

}
